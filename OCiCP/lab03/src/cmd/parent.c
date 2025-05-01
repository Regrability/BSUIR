#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include "error.h"
#include "onSignal.h"
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#define ENABLE(reg, flag)  ((reg) |= (flag))
#define DISABLE(reg, flag) ((reg) &= ~(flag))

pid_t executeProcess(const char *path, char *const *argv, char *const *envp);
pid_t startChildProcess();

pid_t *processArray = NULL;
int processCount = 0;

bool createNewProcess();
bool killLastProcess();
bool killAllProcesses();
bool listProcesses();
bool silenceProcess(int processId);
bool unsilenceProcess(int processId);
bool silenceAllProcesses();
bool unsilenceAllProcesses();
bool prioritizeProcess(int processId);
bool quit();
bool unknownCommand(const char *command);

void onAlarmHandler();
bool handleCommand(const char *command);
bool isFastCommand(int character);
int getInputCharacter();
char *appendCharacterToString(char *str, char *end, char character);
void readCommand(char *buffer, int bufferSize);

int main() {
  onSignal(SIGALRM, onAlarmHandler);
  while (true) {
    char commandBuffer[256];
    readCommand(commandBuffer, sizeof(commandBuffer));
    if (!handleCommand(commandBuffer)) break;
  }
  return !killAllProcesses();
}

pid_t executeProcess(const char *path, char *const *argv, char *const *envp) {
  pid_t childPid = fork();
  if (childPid == 0) {
    if (execve(path, argv, envp) == -1)
      error(CHILD_FAILED, "execve(...) failed, errno: %d", errno);
  }
  return childPid;
}

pid_t startChildProcess()
{
  return executeProcess("build/child", NULL, NULL);

}

bool createNewProcess()
{
  pid_t childPid = startChildProcess();
  printf("Created new process: %d\n", childPid);
  processCount++;
  processArray = realloc(processArray, sizeof(pid_t) * processCount);
  processArray[processCount - 1] = childPid;
  return true;
}

bool killLastProcess()
{
  if (processCount == 0) return true;
  processCount--;
  printf("Killing process: %d\n", processArray[processCount]);
  kill(processArray[processCount], SIGKILL);
  waitpid(processArray[processCount], NULL, 0);
  return true;
}

bool killAllProcesses()
{
  while (processCount)
    killLastProcess();
  free(processArray);
  processArray = NULL;
  return true;
}

bool listProcesses()
{
  system("pstree");
  return true;
}

bool silenceProcess(int processId) {
  if (!(0 <= processId && processId < processCount))
  {
    printf("Silencing: process %d does not exist\n", processId);
    return true;
  }
  kill(processArray[processId], SIGUSR1);
  printf("Silenced process: %d\n", processId);
  return true;
}

bool unsilenceProcess(int processId)
{
  if (!(0 <= processId && processId < processCount))
  {
    printf("Unsilencing: process %d does not exist\n", processId);
    return true;
  }
  kill(processArray[processId], SIGUSR2);
  printf("Unsilenced process: %d\n", processId);
  return true;
}

bool silenceAllProcesses()
{
  for (int i = 0; i < processCount; i++)
    silenceProcess(i);
  return true;
}

bool unsilenceAllProcesses()
{
  alarm(0);
  for (int i = 0; i < processCount; i++)
    unsilenceProcess(i);
  return true;
}

bool prioritizeProcess(int processId)
{
  silenceAllProcesses();
  unsilenceProcess(processId);
  alarm(5);
  return true;
}

bool quit()
{ return false;
}

bool unknownCommand(const char *command)
{
  printf("Unknown command: %s\n", command);
  return true;
}

void onAlarmHandler()
{
  unsilenceAllProcesses();

}

bool handleCommand(const char *command)
{
  if (strcmp(command, "+") == 0) return createNewProcess();
  if (strcmp(command, "-") == 0) return killLastProcess();
  if (strcmp(command, "l") == 0) return listProcesses();
  if (strcmp(command, "k") == 0) return killAllProcesses();
  if (strcmp(command, "s") == 0) return silenceAllProcesses();
  if (strcmp(command, "g") == 0) return unsilenceAllProcesses();
  if (strcmp(command, "q") == 0) return quit();

  int processId = 0;

  if (sscanf(command, "s%d", &processId) == 1) return silenceProcess(processId);
  if (sscanf(command, "g%d", &processId) == 1) return unsilenceProcess(processId);
  if (sscanf(command, "p%d", &processId) == 1) return prioritizeProcess(processId);
  return unknownCommand(command);
}

bool isFastCommand(int character)
{ return strchr("+-q", character) != NULL;

}

int getInputCharacter()
{
  struct termios oldTerminalSettings, currentTerminalSettings;
  tcgetattr(STDIN_FILENO, &currentTerminalSettings);
  oldTerminalSettings = currentTerminalSettings;
  DISABLE(currentTerminalSettings.c_lflag, ECHO);
  DISABLE(currentTerminalSettings.c_lflag, ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &currentTerminalSettings);
  int character = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminalSettings);
  return character;
}

char *appendCharacterToString(char *str, char *end, char character)
{
  if (str == end) return str;
  putchar(character);
  *str = character;
  return str + 1;
}

void readCommand(char *buffer, int bufferSize)
{
  int character = 0;
  char *it = buffer;
  char *end = buffer + bufferSize - 1;
  while ((character = getInputCharacter()) != '\n')
  {
    if (character == 127)
    {
      it = it - 1 < buffer ? buffer : it - 1;
      putchar('\b');
      putchar(' ');
      putchar('\b');
      continue;
    }

    if (isFastCommand(character))
    {
      if (it != buffer) putchar('\n');
      it = buffer + 1;
      char str[2] = {(char)character, 0};
      strcpy(buffer, str);
      break;
    }

    if (character == 0x1b)
    {
      it = appendCharacterToString(it, end, '^');
      it = appendCharacterToString(it, end, '[');
    } else
    {
      it = appendCharacterToString(it, end, character);
    }


    if (it == end)
    {
      for (; character != '\n'; character = getInputCharacter())
        ;
      putchar('\n');
      break;
    }
  }
  *it = 0;
  if (!isFastCommand(*buffer)) putchar('\n');
}

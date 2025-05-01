#define _POSIX_C_SOURCE 199309L
#include "onSignal.h"
#include "timer.h"
#include <memory.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

bool is_silent = false;

struct Coordinates {
  int x, y;
} coordinates = {0};

struct CounterValues {
  int down_down, down_up, up_down, up_up;
} counter_values = {0};

void reset();

void collect();

void print();

void onTimer();

void onUsr1();

void onUsr2();

int main() {
  onSignal(SIGUSR1, onUsr1);
  onSignal(SIGUSR2, onUsr2);
  startIntervalTimer(createTimer(onTimer), us(500));

  while (true) {
    reset();
    for (int i = 0; i < 100000000; i++) {
      coordinates.x = 0;
      coordinates.y = 0;
      coordinates.x = 1;
      coordinates.y = 1;
    }
    if (!is_silent) print();
  }
}


void reset() {
  memset(&coordinates, 0, sizeof(coordinates));
  memset(&counter_values, 0, sizeof(counter_values));
}

void collect() {
  struct Coordinates copy = coordinates;
  if (copy.x && copy.y) counter_values.up_up++;
  if (copy.x && !copy.y) counter_values.up_down++;
  if (!copy.x && copy.y) counter_values.down_up++;
  if (!copy.x && !copy.y) counter_values.down_down++;
}

void print() {
  struct CounterValues copy = counter_values;
  printf(
      "ppid:%d pid:%5d down_down:%4d down_up:%4d up_down:%4d up_up:%4d\n",
      getppid(),
      getpid(),
      copy.down_down,
      copy.down_up,
      copy.up_down,
      copy.up_up
  );
}

void onTimer() { collect(); }

void onUsr1() { is_silent = true; }

void onUsr2() { is_silent = false; }

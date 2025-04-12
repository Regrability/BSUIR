import serial
import serial.tools.list_ports
import time
import tkinter as tk
from tkinter import ttk, messagebox
import random
import re

# Определение доступных COM-портов
ports = serial.tools.list_ports.comports()

# Переменные для хранения портов
port_to_receive_1 = None
port_to_send_1 = None
port_to_receive_2 = None
port_to_send_2 = None

# Функция для ассоциации портов
def associate_port(port_device):
    global port_to_send_1, port_to_receive_1, port_to_send_2, port_to_receive_2  # Указываем, что будем использовать глобальные переменные
    if port_device == "COM5":
        port_to_send_1 =  port_device
    elif port_device == "COM6":
        port_to_receive_1 = port_device
    elif port_device == "COM8":
        port_to_send_2 = port_device
    elif port_device == "COM9":
        port_to_receive_2 = port_device


# Ассоциируем порты
for port in ports:
    associate_port(port.device)

# Параметры соединения
baudrate = 9600

# Форматирование названий пар портов
pair_1 = f"{port_to_send_1} -> {port_to_receive_1}"
pair_2 = f"{port_to_send_2} -> {port_to_receive_2}"

def crc16(data: bytes) -> bytes:
    # Полином для CRC-16
    polynomial = 0xA001
    crc = 0xFFFF

    for byte in data:
        crc ^= byte
        for _ in range(8):
            if (crc & 0x0001) != 0:
                crc >>= 1
                crc ^= polynomial
            else:
                crc >>= 1

    # Возвращаем CRC в виде двух байтов
    return crc.to_bytes(2, byteorder='little')

def corrupt_data(data: bytes, corruption_probability: float = 0.7) -> bytes:
    if random.random() < corruption_probability:
        byte_array = bytearray(data)
        # Выбираем случайный байт и случайный бит в этом байте
        byte_index = random.randint(5, len(byte_array) - 5)
        bit_index = random.randint(0, 7)
        # Искажаем бит
        byte_array[byte_index] ^= (1 << bit_index)
        return bytes(byte_array)
    return data



def decode_packet(data, collizion):
    decoded_data = ""
    packet_size = 12  # Общая длина пакета ($flag, dest, src, data, fcs)
    data = data.replace('[$d]', '$d')
    index_collizion = 0

    # Обрабатываем данные поблочно
    for i in range(0, len(data), packet_size):
        packet = data[i:i + packet_size]

        # Извлекаем полезную нагрузку (длина данных - 4 символа) из пакета
        if len(packet) == packet_size:
            useful_data = packet[4:8]  # Полезные данные начиная с 4 символа (индекса 3)
            fcs_received = packet[8:]  # Получаем FCS из пакета

            # Проверяем, является ли fcs_received допустимой шестнадцатеричной строкой
            if re.match(r'^[0-9A-Fa-f]*$', fcs_received) and len(fcs_received) == 4:  # Должен быть длиной 4
                data_bytes = packet[4:8].encode('utf-8')
                fcs_calculated = crc16(data_bytes)

                # Преобразуем fcs_received в байты
                fcs_received_bytes = bytes.fromhex(fcs_received)

                # Проверяем FCS
                if fcs_received_bytes == fcs_calculated:
                    decoded_data += useful_data.strip() + collizion[index_collizion] + "\n"

            else:
                decoded_data += f"Неверный формат FCS: {fcs_received}\n"
        index_collizion +=1

    return decoded_data


# Функция создания пакета данных с учетом байт-стаффинга и фиксированной длины пакета
def create_packet(message, source_address, n):
    flag = f"${chr(ord('a') + n - 1)}"

    # Обрезаем сообщение до нужной длины и заполняем пробелами, если нужно
    data = message[:n].ljust(n, ' ').replace('$d', '[$d]')  # Заполнение пробелами до длины n

    destination_address = '0'
    source_address = str(source_address)

    # Рассчитываем FCS на основе поля Data
    fcs = crc16(data.encode('utf-8'))

    # Формируем пакет фиксированной длины
    packet = f"{flag}{destination_address}{source_address}{data}{fcs.hex()}"
    return packet


# Эмуляция занятости канала с вероятностью 50%
def is_channel_busy():
    return random.random() < 0.5

# Эмуляция коллизии с вероятностью 60%
def is_collision():
    return random.random() < 0.6

# Функция для прослушивания канала перед передачей данных
def listen_to_channel():
    while is_channel_busy():
        print("Канал занят, ждем...")
        time.sleep(random.uniform(0.1, 0.5))  # Ждем случайное время, если канал занят

# Функция для эмуляции случайной задержки при коллизии
def random_backoff():
    delay = random.uniform(0.1, 1.0)  # Случайная задержка от 100 до 1000 мс
    print(f"Коллизия обнаружена. Задержка перед повторной попыткой: {delay:.2f} сек.")
    time.sleep(delay)





# Функция для отправки и получения данных через COM-порты
def send_and_receive(port_send, port_receive, message, source_address, max_packet_size=4):
    try:
        parity = parity_combobox.get()
        parity_setting = serial.PARITY_NONE

        if parity == "Even":
            parity_setting = serial.PARITY_EVEN
        elif parity == "Odd":
            parity_setting = serial.PARITY_ODD

        ser_send = serial.Serial(port_send, baudrate=baudrate, timeout=2, parity=parity_setting)
        ser_receive = serial.Serial(port_receive, baudrate=baudrate, timeout=2, parity=parity_setting)

        total_bytes_sent = 0
        all_packets = []
        all_received_data = ""
        collizion_ch = 0
        jam_signal = False
        collizion = ""

        # Отправка данных частями
        for i in range(0, len(message), max_packet_size):
            part_message = message[i:i + max_packet_size]

            # Эмулируем прослушивание канала перед отправкой
            listen_to_channel()
            # Создаем пакет
            packet = create_packet(part_message, source_address, n=max_packet_size)

            # Коррумируем данные с 70% вероятностью
            corrupted_packet = corrupt_data(packet.encode('utf-8'))
            all_packets.append(corrupted_packet.decode('utf-8', errors='ignore'))

            # Отправляем пакет
            bytes_to_send = ser_send.write(packet.encode('utf-8'))
            total_bytes_sent += bytes_to_send

            collizion_ch = 0

            # Проверяем на коллизию
            while is_collision():
                collizion_ch += 1
                random_backoff()  # Эмулируем задержку перед повторной попыткой
                jam_signal = True
                if jam_signal:
                    print("приёмник прекратил получать информацию из-за jam-сигнала")


            if collizion_ch > 0:
                collizion += "-"
            else:
                collizion += "+"

            # Ждем и принимаем данные
            time.sleep(0.2)
            received_data = ser_receive.read_all().decode('utf-8', errors='ignore')
            all_received_data += received_data

        ser_send.close()
        ser_receive.close()

        # Декодируем все принятые данные
        decoded_data = decode_packet(all_received_data, collizion)
        # Вернем декодированные данные, общее количество переданных байт и все отправленные пакеты
        return decoded_data, total_bytes_sent, all_packets
    except serial.SerialException as e:
        return str(e), 0, []

# Обработчик отправки сообщений
def handle_send(event=None):
    message = message_entry.get()
    selected_pair = port_pair_combobox.get()

    if not message or not selected_pair:
        messagebox.showerror("Ошибка", "Пожалуйста, выберите пару портов и введите сообщение.")
        return

    # Выбираем нужную пару портов
    if selected_pair == pair_1:
        response, bytes_sent, raw_packets = send_and_receive(port_to_send_1, port_to_receive_1, message,
                                                             source_address=int(port_to_receive_1.replace('COM', '')))
    else:
        response, bytes_sent, raw_packets = send_and_receive(port_to_send_2, port_to_receive_2, message,
                                                             source_address=int(port_to_receive_2.replace('COM', '')))

    # Отображаем результат
    response_text.delete(1.0, tk.END)
    response_text.insert(tk.END, response)
    message_entry.delete(0, tk.END)

    # Обновляем состояние
    if bytes_sent > 0:
        port_speed_label.config(text=f"Скорость порта: {baudrate} бод")
    bytes_sent_label.config(text=f"Количество переданных байт: {bytes_sent}")

    # Отображаем пакеты до декодирования
    packet_text.delete(1.0, tk.END)
    for packet in raw_packets:
        packet_text.insert(tk.END, packet + "\n")

# Создание основного окна
root = tk.Tk()
root.title("Serial Communication")
root.geometry("400x600")

# Выбор пары портов
port_pair_label = tk.Label(root, text="Выберите пару портов:")
port_pair_label.pack(pady=5)
port_pair_combobox = ttk.Combobox(root, values=[pair_1, pair_2])
port_pair_combobox.pack(pady=5)

# Выбор паритета
parity_label = tk.Label(root, text="Выберите паритет:")
parity_label.pack(pady=5)

parity_options = ["None", "Even", "Odd"]
parity_combobox = ttk.Combobox(root, values=parity_options)
parity_combobox.pack(pady=5)
parity_combobox.current(0)  # Установите "None" как значение по умолчанию

# Поле для ввода сообщения
message_label = tk.Label(root, text="Введите сообщение:")
message_label.pack(pady=5)
message_entry = tk.Entry(root)
message_entry.pack(pady=5)

# Привязываем обработчик события нажатия клавиши Enter
message_entry.bind('<Return>', handle_send)

# Поле для вывода полученного ответа
response_label = tk.Label(root, text="Полученный ответ:")
response_label.pack(pady=5)
response_text = tk.Text(root, height=10, width=40)
response_text.pack(pady=5)

# Окно состояния
status_frame = tk.Frame(root)
status_frame.pack(pady=10)

port_speed_label = tk.Label(status_frame, text="Скорость порта: ")
port_speed_label.pack()

bytes_sent_label = tk.Label(status_frame, text="Количество переданных байт: 0")
bytes_sent_label.pack()

# Поле для отображения пакета до декодирования
packet_label = tk.Label(root, text="Пакет до декодирования:")
packet_label.pack(pady=5)
packet_text = tk.Text(root, height=5, width=40)
packet_text.pack(pady=5)

# Запуск основного цикла
root.mainloop()
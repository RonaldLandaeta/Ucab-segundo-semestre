import struct
from time import sleep

# Empaquetar datos
data = struct.pack('iif', 1, 2, 3.14)
print(data)
with open('data_struct.bin', 'wb') as file:
    file.write(data)

sleep(5)

# Desempaquetar datos
with open('data_struct.bin', 'rb') as file:
    data = file.read()
    unpacked_data = struct.unpack('iif', data)
    print(unpacked_data)

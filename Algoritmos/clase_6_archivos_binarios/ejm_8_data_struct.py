import struct
import time


# Escribir datos binarios
with open('struct_file.bin', 'wb') as file:
    data = struct.pack('i', 123)
    file.write(data)

time.sleep(5)

# Leer datos binarios
with open('struct_file.bin', 'rb') as file:
    data = file.read(4)
    number = struct.unpack('i', data)[0]
    print(number)



# usando el operadir wlarus (:=)
with open('ejemplo4.bin', 'rb') as file:
    while byte := file.read(4):
        number = int.from_bytes(byte, byteorder='little')
        print(number)

print(" ********** ")
# sin el operador walrus:
with open('ejemplo4.bin', 'rb') as file:
    byte = file.read(4)
    while byte:
        number = int.from_bytes(byte, byteorder='little')
        print(number)
        byte = file.read(4)
  

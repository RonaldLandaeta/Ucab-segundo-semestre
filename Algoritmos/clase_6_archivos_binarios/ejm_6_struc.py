data = [10, 20, 30, 40]

with open('ejemplo4.bin', 'wb') as file:
    for number in data:
        file.write(number.to_bytes(4, byteorder='little'))

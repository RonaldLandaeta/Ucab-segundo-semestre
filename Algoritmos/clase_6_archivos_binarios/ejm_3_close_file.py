# Escribir datos binarios en un archivo
numero = 16909060
data= (numero).to_bytes(length=8) # si no se indica el byteorder toma 'big' de forma predeterminada
print(data)

with open('data.bin', 'wb') as file:
    file.write(data)
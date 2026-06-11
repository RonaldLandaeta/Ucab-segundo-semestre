# Método tradicional de cerrar un archivo
file = open('data.bin', 'wb')
# Realizar operaciones
file.close()

# Usar el bloque 'with' para manejo automático
with open('data.bin', 'wb') as file:
    file.write(b'\x01\x02\x03\x04')
# El archivo se cierra automáticamente aquí


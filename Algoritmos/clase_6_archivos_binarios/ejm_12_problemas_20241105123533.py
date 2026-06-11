"""
Se tiene un mayorista que desea intercambiar información con sus clientes, de antemano le indica el formato del archivo a recibir, de manera que sus clientes lo puedan leer correctamente. EL mayorista usa Python como lenguaje en su sistema, pero desconoce que usan los clientes.

A continuación los datos a guardar en el archivo:
productos = [
    (123, "Manzana", 0.99),
    (456, "Banana", 0.75),
    (789, "Naranja", 1.25)
]

El formato que usa para el archivo es: "little-endian", un entero para el código, usa una cadena de máximo 20 caracteres para el nombre del producto y un flotante para el precio unitario.

¿qué tipo de módulo usaría para distribuir el archivo?
"""
import struct

# Definimos el formato de cada registro
FORMATO = '<i20sf'  # '<' little-endian, 'i' entero, '20s' cadena de 20 caracteres, 'f' flotante


productos = [
    (123, "Manzana", 0.99),
    (456, "Banana", 0.75),
    (789, "Naranja", 1.25)
]

# Abrimos el archivo en modo escritura binaria
with open('productos.bin', 'wb') as f:
    for producto in productos:
        # Empaquetamos los datos según el formato
        datos = struct.pack(FORMATO, producto[0], producto[1].encode('utf-8'), producto[2])
        # Escribimos los datos en el archivo
        f.write(datos)


TAMANO_REGISTRO = struct.calcsize(FORMATO)
# Abrimos el archivo en modo lectura binaria
with open('productos.bin', 'rb') as f:
    while True:
        # Leemos un registro
        datos = f.read(TAMANO_REGISTRO)
        if not datos:
            break
        # Desempaquetamos los datos
        codigo, nombre, precio = struct.unpack(FORMATO, datos)
        # Imprimimos los datos
        print(f"Código: {codigo}, Nombre: {nombre.decode('utf-8').rstrip()}, Precio: {precio}")
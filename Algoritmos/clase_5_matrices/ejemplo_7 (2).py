"""
Imagina que tienes una imagen representada como una matriz 𝑁×𝑁, donde cada elemento de la matriz es un 
píxel de la imagen. El objetivo es rotar la imagen 90 grados en sentido horario utilizando ciclos for o 
while. No se puede usar NumPy para realizar la rotación, pero puedes declarar la matriz original manualmente.

Datos:
Tienes una matriz cuadrada que representa una imagen, donde cada valor de la matriz representa un píxel.

Ejemplo de matriz:
                     1    2    3                       7    4    1
		imagen =     4    5    6    imagen rotada      8    5    2
                     7    8    9                       9    6    3

Cree un programa que dada una matriz cuadrada la rote 90º
"""
def rotar_imagen_90_grados(imagen):
    size = len(imagen)  # se asume una matriz cuadrada

    rotada = [[0 for _ in range(3)] for _ in range(3)]

    for i in range(size):
        for j in range(size):
            rotada[j][size - 1 -i] = imagen[i][j]

    return rotada

# segunda opción
def rotar_imagen_90_grados_2(imagen):
    size = len(imagen)

    rotada = [[0 for _ in range(3)] for _ in range(3)]

    invertida = imagen[::-1]

    for i in range(size):
        for j in range(size):
            rotada[i][j] = invertida[j][i]
    return rotada



imagen = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
imagen_rotada = rotar_imagen_90_grados(imagen)
imagen_rotada2 = rotar_imagen_90_grados_2(imagen)

print("imagen normal:")
print(imagen)

print()

print("imagen rotada: ")
print(imagen_rotada)

print()

print("imagen rotada con segundo método: ")
print(imagen_rotada2)


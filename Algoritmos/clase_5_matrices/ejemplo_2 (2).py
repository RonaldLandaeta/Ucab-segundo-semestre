# usando listas anidadas

matrix_a = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print(matrix_a)

print()
# declaración de una matriz

print()
# usando comprensión de listas:
matrix_b = [[col + row * 3 for col in range(1, 4)] for row in range(3)]

print(matrix_b)
# slicing de una matriz
matriz_b = [
    [1, 2, 3],
    [4 ,5, 6],
    [7, 8, 9]
]

# ejemplo de slicing:
sub_matriz = [fila[:2] for fila in matriz_b[:2]]

print(sub_matriz)
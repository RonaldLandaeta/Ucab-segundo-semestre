# Multiplicación de matrices
matriz_a = [
    [1, 2, 3],
    [4 ,5, 6],
    [7, 8, 9]
]

matriz_b = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]

print("matriz_a: ",matriz_a)
print("matriz_b: ", matriz_b)

# multiplicación de matrices
matriz_mult = [[0 for _ in range(3)] for _ in range(3)]

for i in range(len(matriz_a)):                                      # filas de matriz_a
    for j in range(len(matriz_b[0])):                               # columnas de matriz_b
        for k in range(len(matriz_b)):                              # filas de matriz_b
            matriz_mult[i][j] += matriz_a[i][k] * matriz_b[k][j]

print("matriz_mult:")
print(matriz_mult)
print()

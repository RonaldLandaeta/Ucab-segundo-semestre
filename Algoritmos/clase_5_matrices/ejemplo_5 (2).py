# transposición de una matriz
matriz_a = [
    [1, 2, 3],
    [4 ,5, 6],
    [7, 8, 9]
]

matriz_transpuesta = [[0 for _ in range(3)] for _ in range(3)]
for i in range(len(matriz_a)):
    for j in range(len(matriz_a[0])):
        matriz_transpuesta[j][i] = matriz_a[i][j]

print("matriz_transpuesta:")
print(matriz_transpuesta)
print()


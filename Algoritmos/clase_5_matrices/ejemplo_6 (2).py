matriz_a = [
    [1, 2, 3],
    [4 ,5, 6],
    [7, 8, 9]
]

matriz_b = [
    [3, 2, 1],
    [7 ,8, 9],
    [4, 5, 6]
]

print("matriz_a: ",matriz_a)
print("matriz_b:", matriz_b)

# suma de matrices
matriz_suma = [[0 for _ in range(3)] for _ in range(3)]
for i in range(len(matriz_a)):
    for j in range(len(matriz_a[0])):
        matriz_suma[i][j] = matriz_a[i][j] + matriz_b[i][j]

print("matriz_suma:")
print(matriz_suma)

# resta de matrices
matriz_resta = [[0 for _ in range(3)] for _ in range(3)]
for i in range(len(matriz_a)):
    for j in range(len(matriz_a[0])):
        matriz_resta[i][j] = matriz_a[i][j] - matriz_b[i][j]

print("matriz_resta:")
print(matriz_resta)



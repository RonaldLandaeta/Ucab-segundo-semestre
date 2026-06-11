matriz_b = [
    [1, 2, 3],
    [4 ,5, 6],
    [7, 8, 9]
]

print(matriz_b)
escalar = 8


matriz_result = [[0 for _ in range(len(matriz_b))] for _ in range(len(matriz_b))]
for i in range(len(matriz_b)):
    for j in range(len(matriz_b[0])):
        matriz_result[i][j] = escalar * matriz_b[i][j] 

print(matriz_result)

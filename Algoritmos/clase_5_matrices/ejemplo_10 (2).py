# características de una matriz

matriz_b = [
    [1, 2, 3],
    [4 ,5, 6],
    [7, 8, 9]
]

print(matriz_b)


# Obtener forma de la matriz (número de filas y columnas)
forma = len(matriz_b), len(matriz_b[0])
print(f"la forma de matriz_b son: {forma}")

# Obtener dimensión de la matriz (número de dimensiones)
dimensiones = len(forma)
print(f"la dimensión de matriz_b es: {dimensiones}")

# Obtener tamaño (número total de elementos) de la matriz
# también asi:
size = len(matriz_b) * len(matriz_b[0])
print(f"el tamaño de matriz_b es: {size} elementos")

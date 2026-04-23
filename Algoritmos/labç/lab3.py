
lista_original = [13, 10, 22, 18, 32, 39, 21, 5, 33, 15, 18, 2, 9, 31, 18, 7, 23, 27, 28, 9, 31, 15, 7, 28, 18]
lista_sin_repetidos = []

for numero in lista_original:
    if numero not in lista_sin_repetidos:
        lista_sin_repetidos.append(numero)

print("Lista original:", lista_original)
print("Lista sin repetidos:", lista_sin_repetidos)


def busqueda_secuencial(arreglo, objetivo):
    for i in range(len(arreglo)):
        if arreglo[i] == objetivo:
            return i
    return -1

# Ejemplo de uso
arreglo = [5, 3, 1, 4, 2]
objetivo = 4
resultado = busqueda_secuencial(arreglo, objetivo)
print(f'Elemento {objetivo} encontrado en la posición: {resultado}')
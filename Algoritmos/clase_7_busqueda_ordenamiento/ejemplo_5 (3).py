def busqueda_binaria_recursiva(arreglo, objetivo, inicio, fin):
    # Caso base: si el rango es inválido
    if inicio > fin:
        return -1
    
    # Calcular el punto medio
    medio = (inicio + fin) // 2

    # Si el objetivo está en el medio, retornar su índice
    if arreglo[medio] == objetivo:
        return medio

    # Si el objetivo es menor que el elemento del medio, buscar en la mitad izquierda
    elif arreglo[medio] > objetivo:
        return busqueda_binaria_recursiva(arreglo, objetivo, inicio, medio - 1)

    # Si el objetivo es mayor que el elemento del medio, buscar en la mitad derecha
    else:
        return busqueda_binaria_recursiva(arreglo, objetivo, medio + 1, fin)

# Ejemplo de uso
arreglo = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
objetivo = 7
resultado = busqueda_binaria_recursiva(arreglo, objetivo, 0, len(arreglo) - 1)
print(f'El elemento {objetivo} encontrado en la posición: {resultado}')

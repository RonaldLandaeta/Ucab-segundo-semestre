def merge_sort(array):
    """
    Función principal que ordena una lista utilizando el algoritmo Mergesort.
    Es una función recursiva que implementa la estrategia de "divide y vencerás".
    """
    # Caso base de la recursión:
    # Si la lista tiene 1 o 0 elementos, ya está ordenada.
    if len(array) > 1:

        # 1. Fase de DIVISIÓN:
        # Encontrar el punto medio de la lista para dividirla en dos mitades.
        mid = len(array) // 2

        # Usando 'slicing' de Python para crear las dos sub-listas.
        left_half = array[:mid]
        right_half = array[mid:]

        # Llamada recursiva en la primera mitad.
        # Esto continuará dividiendo la lista hasta que solo queden elementos individuales.
        merge_sort(left_half)

        # Llamada recursiva en la segunda mitad.
        merge_sort(right_half)

        # 2. Fase de UNIÓN (Merge):
        # Una vez que las sub-listas están ordenadas, las unimos de forma ordenada.
        
        # Inicializamos los punteros para recorrer las dos sub-listas (i, j)
        # y el puntero para la lista principal (k).
        i = 0
        j = 0
        k = 0

        # Recorremos ambas sub-listas y comparamos sus elementos.
        while i < len(left_half) and j < len(right_half):
            # Si el elemento de la izquierda es menor, lo colocamos en la lista principal.
            if left_half[i] < right_half[j]:
                array[k] = left_half[i]
                i += 1
            # Si no, colocamos el elemento de la derecha.
            else:
                array[k] = right_half[j]
                j += 1
            # Avanzamos el puntero de la lista principal.
            k += 1

        # Después del bucle anterior, una de las sub-listas se habrá agotado.
        # Comprobamos si quedan elementos en 'left_half'.
        while i < len(left_half):
            array[k] = left_half[i]
            i += 1
            k += 1

        # Comprobamos si quedan elementos en 'right_half'.
        while j < len(right_half):
            array[k] = right_half[j]
            j += 1
            k += 1

if __name__ == "__main__":
    array = [38, 27, 43, 3, 9, 82, 10]
    print(f"Arreglo original: {array}")
    merge_sort(array)
    print(f"EL arreglo ordenado es: {array}")

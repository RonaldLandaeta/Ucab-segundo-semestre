def heapify(array, n, i):
    """
    Esta es la función clave para mantener la propiedad de Max-Heap en un
    subárbol con raíz en el índice 'i'.
    'n' es el tamaño del heap (que puede ser menor que el tamaño total de la lista
    a medida que se ordena).
    'i' es el índice del nodo raíz del subárbol que queremos "arreglar".
    """
    largest = i         # Inicializamos 'largest' (el más grande) como la raíz del subárbol.
    left = 2 * i + 1    # Fórmula para encontrar el índice del hijo izquierdo.
    right = 2 * i + 2   # Fórmula para encontrar el índice del hijo derecho.

    # Paso 1: Comparamos la raíz con sus hijos.
    # Verificamos si el hijo izquierdo existe (está dentro de los límites del heap)
    # y si su valor es mayor que el de la raíz actual.
    if left < n and array[i] < array[left]:
        largest = left

    # Hacemos lo mismo con el hijo derecho. Verificamos si existe y si es
    # mayor que el 'largest' que hemos encontrado hasta ahora (que podría ser la raíz o el hijo izquierdo).
    if right < n and array[largest] < array[right]:
        largest = right

    # Paso 2: Realizar el cambio si es necesario.
    # Si 'largest' ha cambiado, significa que uno de los hijos era más grande que la raíz.
    if largest != i:
        # Intercambiamos la raíz con el hijo más grande.
        array[i], array[largest] = array[largest], array[i]

        # ¡Importante! Después del intercambio, el subárbol donde se movió la raíz original
        # podría haber perdido la propiedad de Max-Heap. Por lo tanto, llamamos a heapify
        # recursivamente sobre ese subárbol para asegurarnos de que todo quede en orden.
        heapify(array, n, largest)

def heap_sort(array):
    """
    Función principal para ordenar una lista usando el algoritmo Heapsort.
    """
    n = len(array)

    # --- FASE 1: Construir un Max-Heap a partir de la lista desordenada ---
    # Para construir el heap, aplicamos 'heapify' a todos los nodos que no son hojas.
    # El último nodo padre se encuentra en el índice n // 2 - 1.
    # Iteramos hacia atrás desde ese nodo hasta la raíz (índice 0).
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)

    # --- FASE 2: Extraer elementos del heap uno por uno ---
    # En este punto, el elemento más grande de la lista está en la raíz (arr[0]).
    # Iteramos desde el final de la lista hacia el principio.
    for i in range(n - 1, 0, -1):
        # Movemos la raíz actual (el máximo) al final de la porción no ordenada de la lista.
        # Este elemento ya queda en su posición ordenada final.
        array[i], array[0] = array[0], array[i] #intercambio

        # Después del intercambio, el nuevo elemento en la raíz puede haber roto la
        # propiedad del heap. Llamamos a heapify en el heap reducido (su tamaño ahora es 'i').
        # Le pasamos el índice 0 para que empiece a arreglar desde la nueva raíz.
        heapify(array, i, 0)

if __name__ == "__main__":
    array = [38, 27, 43, 3, 9, 82, 10]
    print(f"EL arreglo desordenado: {array}")
    heap_sort(array)
    print(f"El arreglo ordenado es: {array}")

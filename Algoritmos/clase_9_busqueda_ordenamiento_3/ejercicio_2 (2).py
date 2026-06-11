"""
Dada una lista de números enteros, implementa HeapSort para ordenarla en orden descendente.
"""
def heapify_desc(array, n, i):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and array[i] > array[left]:
        smallest = left

    if right < n and array[smallest] > array[right]:
        smallest = right

    if smallest != i:
        array[i], array[smallest] = array[smallest], array[i]
        heapify_desc(array, n, smallest)

def heap_sort_desc(array):
    n = len(array)

    for i in range(n // 2 - 1, -1, -1):
        heapify_desc(array, n, i)

    for i in range(n - 1, 0, -1):
        array[i], array[0] = array[0], array[i]
        heapify_desc(array, i, 0)

numbers = [15, 3, 17, 10, 84, 19, 6, 22, 9]
heap_sort_desc(numbers)
print("Arreglo ordenado en orden descendente:", numbers)

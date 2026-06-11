def partition(arr, low, high):
    mid = (low + high) // 2
    pivot = arr[mid]
    arr[mid], arr[high] = arr[high], arr[mid]  # Movemos el pivote al final
    i = low - 1
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Colocamos el pivote en su posición correcta
    return i + 1

def quicksort(arr, low=0, high=None):
    if high is None:
        high = len(arr) - 1
    if low < high:
        pi = partition(arr, low, high)
        quicksort(arr, low, pi - 1)
        quicksort(arr, pi + 1, high)
    
    return arr


arreglo = [15, 27, 1, 12, 6, 18, 9, 21, 13, 5]
print(arreglo)
ordenado = quicksort(arreglo)
print(ordenado)
"""
ejemplo de implementación del algoritmos de burbuja
"""
def bubble_sort(arr):
    paso = 0
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j] #<= Ojo: esto solo en Python
            print(f"paso {paso}: {arr}")

            paso += 1
    return arr

arreglo = [15, 27, 1, 12, 6, 18, 9, 21, 13, 5]
print(arreglo)

ordenado = bubble_sort(arreglo)
print(ordenado)



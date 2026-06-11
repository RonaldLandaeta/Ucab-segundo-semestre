"""
1. Ordenar la lista [64, 25, 12, 22, 11, 90] usando el algoritmo de burbuja.
2. Ordenar la lista [3, 6, 8, 10, 1, 2, 1] usando el algoritmo quicksort.
3. Implementar el algoritmo de burbuja para ordenar una lista de cadenas de caracteres. 
El arreglo es:  ["manzana", "naranja", "pera", "uva", "kiwi"]
4. Implementar el algoritmo quicksort para ordenar una lista de números 
decimales. El arreglo es: [3.4, 1.2, 5.6, 9.0, 2.1]
"""
def optimized_bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivote = arr[len(arr) // 2]
        izquierda = []
        centro = []
        derecha = []

        for x in arr:
            if x < pivote:
                izquierda.append(x)
            elif x == pivote:
                centro.append(x)
            else:
                derecha.append(x)

        return quicksort(izquierda) + centro + quicksort(derecha)


# 1. 
print("problema 1")
arreglo1 = [64, 25, 12, 22, 11, 90]
print(arreglo1)
optimized_bubble_sort(arreglo1)
print(arreglo1)

print()

# 2.
print("problema 2")
arreglo2 = [3, 6, 8, 10, 1, 2, 1]
print(arreglo2)
ordenado2 = quicksort(arreglo2)
print(ordenado2)

print()

# 3.
print("problema 3")
arreglo3 = ["manzana", "naranja", "pera", "uva", "kiwi"]
print(arreglo3)
ordenado3 = optimized_bubble_sort(arreglo3)
print(arreglo3)

print()

# 4.
print("problema 4")
arreglo4 = [3.4, 1.2, 5.6, 9.0, 2.1]
print(arreglo4)
ordenado4 = quicksort(arreglo4)
print(ordenado4)


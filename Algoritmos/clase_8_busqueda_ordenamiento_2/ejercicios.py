"""
Algoritmo recursivo quicksort
"""
def quicksort(arr, paso = 0):
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
            print(f"paso {paso}: {arr}, pivote: {pivote}, izquierda: {izquierda}, centro: {centro}, derecha: {derecha}")
            paso += 1

        return quicksort(izquierda, paso=paso) + centro + quicksort(derecha, paso=paso)
    

arreglo = [15, 27, 1, 12, 6, 18, 9, 21, 13, 5]
print(arreglo)
ordenado = quicksort(arreglo)
print(ordenado)
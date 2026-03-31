def busqueda_binaria(arr, target):
    low = 0 
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return f"La fruta {buscar} está en la posición {mid}"
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return f"La fruta {buscar} NO fue encontrada"

frutas = ["cambur", "kiwi", "limón", "manzana", "melón", "naranja", "pera"]
buscar = "naranja"
print(busqueda_binaria(frutas, buscar))
# El tiempo de ejecución de este algoritmo es O(log n) ya que el número de operaciones crece logarítmicamente con el tamaño de la entrada N.
# este algoritmo usa la busqueda de forma binaria, lo que significa que divide el arreglo en mitades sucesivas para encontrar el elemento objetivo. Esto hace que el tiempo de ejecución crezca logarítmicamente con el tamaño del arreglo, lo que es mucho más eficiente que una búsqueda lineal (O(n)) para arreglos grandes.
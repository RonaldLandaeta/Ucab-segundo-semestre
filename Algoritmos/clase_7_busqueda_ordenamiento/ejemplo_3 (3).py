"""
Implementar una función de búsqueda secuencial que cuente cuántas veces aparece el elemento 9 en el arreglo.
"""
arreglo: list = [4, 9, 2, 3, 9, 5, 9, 9, 8, 2, 9, 1, 6, 7, 6, 3, 6, 7, 6, 3, 10, 9, 4, 10, 7, 1, 8, 4, 4, 7]

def cuenta_elemento(arreglo: list, target: int) -> str:
    count: int = 0
    for item in arreglo:
        if item == target:
            count += 1

    return f"El número {target} está {count} veces en el arreglo"


print(cuenta_elemento(arreglo=arreglo, target= 3))

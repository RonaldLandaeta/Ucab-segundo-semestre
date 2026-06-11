"""
Implementar una función de ordenamiento por inserción directa que ordene una lista de cadenas de texto.
"""

palabras = ["perro", "casa", "pelota", "avion", "naranja", "dedal"]

def ordena_palabras(arreglo):
    for i in range(len(arreglo)):
        key = arreglo[i]
        j = i - 1
        while j >= 0 and arreglo[j] > key:
            arreglo[j + 1] = arreglo[j]
            j -= 1
        arreglo[j + 1] = key
    
    return arreglo


# Ejemplo de uso
resultado = ordena_palabras(palabras)
print(f"El arreglo ordenado quedó {resultado}")
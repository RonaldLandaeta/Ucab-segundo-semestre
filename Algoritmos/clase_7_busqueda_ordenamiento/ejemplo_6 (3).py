def ordenacion_por_insercion(arreglo):
    for i in range(len(arreglo)):
        key = arreglo[i]
        j = i - 1
        while j >= 0 and arreglo[j] > key:
            arreglo[j + 1] = arreglo[j]
            j -= 1
        arreglo[j + 1] = key
        print(f"paso {i}: {arreglo}")

    return arreglo


# Ejemplo de uso
arreglo = [6, 3, 5, 2, 8, 1, 7]
resultado = ordenacion_por_insercion(arreglo)
print(f"El arreglo ordenado quedó {resultado}")
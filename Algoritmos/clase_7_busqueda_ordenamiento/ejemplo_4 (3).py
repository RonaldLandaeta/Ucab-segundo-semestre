def busqueda_binaria(arreglo, objetivo):
    inicio = 0
    fin = len(arreglo) - 1
    while inicio <= fin:
        # se busca la mitad del segmento
        medio = (inicio + fin) // 2
        if arreglo[medio] == objetivo:
            # si lo encuentra lo devuelve
            return medio
        # como está ordenado pregunta si el segmento
        # superior contiene el objetivo
        elif arreglo[medio] < objetivo:
            # selecciona la parte superior
            inicio = medio + 1
        else:
            # de lo contarrio, selecciona la parte inferior
            fin = medio - 1
            # se ejecuta hasta que lo consiga
    return -1

# Ejemplo de uso
arreglo = [1, 2, 3, 4, 5, 8, 9, 10, 11, 12]
objetivo = 4
resultado = busqueda_binaria(arreglo, objetivo)
print(f'El elemento {objetivo} encontrado en la posición: {resultado}')

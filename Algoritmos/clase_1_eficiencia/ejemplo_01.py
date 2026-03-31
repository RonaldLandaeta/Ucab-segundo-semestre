# algoritmo ineficiente
def busqueda_ineficiente(arreglo, elemento):
    for i in range(len(arreglo)):
        if arreglo[i] == elemento:
            return True
    return False

# algoritmo eficiente:
def busqueda_eficiente(arreglo, elemento):
    return elemento in arreglo



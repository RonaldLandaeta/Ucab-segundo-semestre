import random
import time

big_arr = random.sample(range(100000000), 1000000)

# algoritmo ineficiente:
def busqueda_ineficiente(arreglo, elemento):
    start = time.time()
    found_it = False
    for i in range(len(arreglo)):
        if arreglo[i] == elemento:
            print(arreglo[i])
            found_it = True
    end = time.time()
    print(f"Ineficiente: {end - start} seg")
    return found_it

# algoritmo eficiente:
def busqueda_eficiente(arreglo, elemento):
    start = time.time()
    found_it =  elemento in arreglo
    end = time.time()
    print(f"Eficiente: {end - start} seg")
    return found_it

result1 = busqueda_ineficiente(big_arr, 123456)
result2 = busqueda_eficiente(big_arr, 123456)
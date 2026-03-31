import random
import time

big_arr1 = random.sample(range(1_000_000), 10_000)
big_arr2 = random.sample(range(10_000_000), 100_000)
big_arr3 = random.sample(range(100_000_000), 1_000_000)

def busqueda_eficiente(arreglo, elemento):
    start = time.time()
    found_it =  elemento in arreglo
    end = time.time()
    print(f"Eficiente: {end - start} seg")
    return found_it

result = busqueda_eficiente(big_arr1, 1234)
result = busqueda_eficiente(big_arr2, 1234)
result = busqueda_eficiente(big_arr3, 1234)
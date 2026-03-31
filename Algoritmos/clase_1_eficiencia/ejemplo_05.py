# Tanto en el caso de un valor de entrada de tamaño N
def print_numbers_to_n(n):
    for i in range(1, n+1):
        print(i, end=" ")

print_numbers_to_n(10)

# igualmente un array de N elementos
print()
frutas = ["manzana", "naranja", "pera", "kiwi", "melón"]

def print_all_elements(arr):
    for item in arr:
        print(item, end=" ")

print_all_elements(frutas)
print()

"""
No importa si en cada ciclo realizamos más o menos trabajo ya que 
aunque pudiera parecer que tenemos un logaritmo que tarda el doble 
o el triple, algo como O(3n) lo simplificamos a O(n)
"""
def print_more_numbers_to_n(n):
    for i in range(1, n+1):
        print(i, end=" ")
    print()
    
    for i in range(1, n+1):
        print(i, end=" ")
    print()
    
    for i in range(1, n+1):
        print(i, end=" ")
    print()

print_more_numbers_to_n(10)

#es un algoritmo de orden O(n) ya que el tiempo de ejecución crece linealmente con el tamaño de la entrada.
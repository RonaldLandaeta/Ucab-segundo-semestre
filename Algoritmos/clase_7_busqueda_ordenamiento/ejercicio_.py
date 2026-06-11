"""
Escribe una función que realice una búsqueda secuencial en un arreglo de números 
enteros y devuelva el índice del primer elemento que sea igual a un número objetivo. 
Si el elemento no se encuentra, la función debe devolver -1.
	arreglo = [10, 23, 45, 70, 11, 15] 
	objetivo = 70
"""

arreglo = [10, 23, 45, 70, 11, 15]
objetivo = 70

def busqueda_secuencial(arreglo:list, objetivo: int) -> int:
	for i in range(len(arreglo)):
		if arreglo[i] == objetivo:
			return i
	else:
		return -1
	

resultado: int = busqueda_secuencial(arreglo=arreglo, objetivo=objetivo)
if resultado >= 0: 
	print(f"El elemento {objetivo } está en el índice {resultado}") 
else: 
	print("No encontrado")
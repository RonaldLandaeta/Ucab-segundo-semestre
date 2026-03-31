frutas = ["manzana", "naranja", "pera", "kiwi", "melón"]

def busqueda_fuerza_bruta(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return f"Encontrado {target} en el indice: {i}"
    
    return f"No se encontró: {target}"

print(busqueda_fuerza_bruta(frutas, "kiwi"))
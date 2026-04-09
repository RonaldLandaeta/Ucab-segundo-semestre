def factorial(n, count=0):
    # Paso 1: Caso base
    if n == 0 or n == 1:
        return 1
    
    # Paso 2: Caso recursivo
    else:
        # Paso 3: Llamada recursiva
        count += 1
        print(f"llamadas: {count}")
        return n * factorial(n-1, count)
    
n = 5
print(f"{n}! = {factorial(n)}")
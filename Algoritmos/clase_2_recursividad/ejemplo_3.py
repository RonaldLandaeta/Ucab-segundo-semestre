def calcular_secuencia_a(n):
    # Caso base
    if n == 0:
        return 0
    # Caso recursivo
    else:
        # Llamada indirecta a la función B
        return n - calcular_secuencia_b(calcular_secuencia_a(n-1))

def calcular_secuencia_b(n):
    # Caso base
    if n == 0:
        return 1
    # Caso recursivo
    else:
        # Llamada indirecta a la función A
        return n - calcular_secuencia_a(calcular_secuencia_b(n-1))

# Probemos la función
n_terms = 5 
for i in range(n_terms):
    print(f"Secuencia({i}): {calcular_secuencia_a(i)}")
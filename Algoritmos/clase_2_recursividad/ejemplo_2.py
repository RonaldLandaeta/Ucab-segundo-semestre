def fibonacci(n):
    # Caso base
    if n <= 1:
        return n
    # Caso recursivo
    else:
        # Llamadas recursivas
        return fibonacci(n-1) + fibonacci(n-2)

# Probemos la función
n_terms = 10
for i in range(n_terms):
    print(f"Fibonacci({i}): {fibonacci(i)}")
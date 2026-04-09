"""
    Calcula la suma de los dígitos de un número entero de forma recursiva.
"""
def suma_digitos(n):
    if n < 10:  # Caso base: si el número tiene un solo dígito, la suma es el número mismo
        return n
    else:
        # Caso recursivo: sumar el último dígito con la suma de los dígitos restantes
        return n % 10 + suma_digitos(n // 10)

# Ejemplo
numero = 784
resultado = suma_digitos(numero)
print(f"La suma de los dígitos de {numero} es: {resultado}")
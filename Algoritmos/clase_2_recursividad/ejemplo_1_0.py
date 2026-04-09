# calculo del factorial usando una función iterativa

def factorial_iterativo(n):
    factorial = 1
    for i in range(2, n + 1):
        factorial *= i

    return factorial

n = 5
print(f"{n}! = {factorial_iterativo(n)}")
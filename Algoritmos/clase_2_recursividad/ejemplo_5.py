def pow(x, n):
    if n == 0:
        return 1
    else:
        return x * pow(x, n-1)
    
x = 2
n = 10
print(f"La potencia de {x} ^ {n} es: {pow(x, n)}")
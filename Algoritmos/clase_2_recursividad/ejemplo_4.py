def funcion_externa(x):
    def funcion_interna(y):
        if y > 0:
            # Llamada anidada
            print(f"FuncionInterna({y}): {y}")
            funcion_interna(y-1)
    
    # Llamada a la función interna
    funcion_interna(x)
    return x

# Probemos la función
numero = 5
print("El resultado es:", funcion_externa(numero))


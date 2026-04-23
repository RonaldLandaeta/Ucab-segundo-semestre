precios: float
cantidads: int
total: float
precios = [8.35, 10.5, 12.03, 21.25, 6.75]
cantidads= [20, 14,12,16,9]
total = 0
for i,j in zip(precios,cantidads):
    total += i * j
print("El total a pagar es: ", total)

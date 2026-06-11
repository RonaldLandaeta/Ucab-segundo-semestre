""" 
Una empresa de fabricación produce tres tipos de productos: A, B y C. Estos productos 
requieren diferentes cantidades de recursos (materiales, mano de obra, y energía) para 
su producción. El objetivo es calcular el costo total de producción de cada producto, 
considerando los recursos utilizados y sus costos.

la matriz de representación de los productos y recursos sería:

            materiales | mano de obra  |  energía |
producto A |    5      |      3        |     2    |
producto B |    4      |      4        |     3    |
producto C |    6      |      5        |     4    |

Los costos asociados a materiales, mano de obra y energía:

        materiales | mano de obra  |  energía |
costos |     10    |      20       |    15    |

Calcular el costo de producción de cada producto, y el costo total
"""

recursos = [[5, 3, 2], [4, 4, 3], [6, 5, 4]]
costos = [10, 20, 30]

print("recursos: ")
print(recursos)
print("costos: ")
print(costos)

costos_totales = []

for i in range(len(recursos)):
    costo_producto = 0
    for j in range(len(costos)):
        costo_producto += recursos[i][j] * costos[j]

    costos_totales.append(costo_producto)

for i in range(len(costos_totales)):
    print(f"El precio del producto {chr(65 + i)} es {costos_totales[i]}")
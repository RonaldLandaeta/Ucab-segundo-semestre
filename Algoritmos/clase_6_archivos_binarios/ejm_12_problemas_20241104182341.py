"""
Se tiene un programa que trabaja con una gran cantidad de datos y se desea guardar esos datos de forma segura, preservando su tipo y estructura de los datos. 
Para probar tenemos lo siguiente:

datos_experimento = [ 
    ["temperatura", 20, 22, 25, 28],
    ["humedad", 60, 58, 62, 65],
    ["resultados", 1.2, 1.5, 1.8, 2.1]
]

Se trabaja solo con Python, ¿Cómo lo podemos almacenar y recuperar adecuadamente?
"""

import pickle

datos_experimento = [ 
    ["temperatura", 20, 22, 25, 28],
    ["humedad", 60, 58, 62, 65],
    ["resultados", 1.2, 1.5, 1.8, 2.1]
]

# Guardar los datos en un archivo
with open('datos_experimento.pkl', 'wb') as f:
    pickle.dump(datos_experimento, f)

# Cargar los datos desde el archivo
with open('datos_experimento.pkl', 'rb') as f:
    datos_cargados = pickle.load(f)

# Verificar que los datos se hayan cargado correctamente
print(datos_cargados)
import pickle

# Definir una matriz de empleados (lista de listas)
# Cada sublista contiene: [ID, Nombre, Edad, Salario]
empleados = [
    [1, 'Alicia', 30, 5000],
    [2, 'Alberto', 25, 4500],
    [3, 'Carlos', 35, 5500]
]

# Guardar la matriz de empleados en un archivo binario usando pickle
with open('empleados.pickle', 'wb') as file:
    pickle.dump(empleados, file)

# Cargar la matriz de empleados desde el archivo binario usando pickle
with open('empleados.pickle', 'rb') as file:
    loaded_empleados = pickle.load(file)
    print(loaded_empleados)


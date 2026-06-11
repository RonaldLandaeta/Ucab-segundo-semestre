import pickle
from time import sleep

# Ejemplo de Uso de pickle para guardar y cargar datos binarios

# Guardar datos en archivo binario usando pickle
data = (1, 2, 3.14)
with open('data_pickle.bin', 'wb') as file:
    pickle.dump(data, file)

sleep(5)

# Cargar datos desde archivo binario usando pickle
with open('data_pickle.bin', 'rb') as file:
    loaded_data = pickle.load(file)
    print(loaded_data)

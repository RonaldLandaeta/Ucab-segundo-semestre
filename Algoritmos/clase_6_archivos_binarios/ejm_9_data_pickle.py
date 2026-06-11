import pickle
import time

# Guardar objeto en archivo binario
data = {'key': 'value'}
with open('data.pickle', 'wb') as file:
    pickle.dump(data, file)

time.sleep(5)


# Cargar objeto desde archivo binario
with open('data.pickle', 'rb') as file:
    loaded_data = pickle.load(file)
    print(loaded_data)

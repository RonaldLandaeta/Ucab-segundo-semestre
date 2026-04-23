# Buscar todas las palabras que comienzan con 'a'
import re

texto = "El perro es un animal domestico"
patron = r'a\w+'
coincidencias = re.findall(patron, texto)
print(coincidencias)
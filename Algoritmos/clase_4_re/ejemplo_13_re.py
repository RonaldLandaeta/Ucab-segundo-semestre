# reemplaza todas las vocales

import re

texto = "Hola, mundo!"
nuevo_texto = re.sub(r"[aeiou]", "*", texto)
print(nuevo_texto) 
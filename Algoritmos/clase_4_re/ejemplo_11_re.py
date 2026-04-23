"""
Encontrar las palabras que tengan solo tres letras en un texto
"""
import re

texto = "El gato juega con una pelota."
patron = r"\b\w{3}\b"
coincidencias = re.findall(patron, texto)
print(coincidencias)
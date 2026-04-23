"""
Encontrar todas las ocurrencias de la letra a en un texto
"""
import re

text = "Mari tenía un corderito"
matches = re.findall('a', text)
print(matches)

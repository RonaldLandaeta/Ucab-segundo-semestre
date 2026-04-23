"""
Reemplazo de texto usando regex

Se desea reemplazar 'color' por 'colour'
"""
import re

text = "The color of the sky is blue."
pattern = r'\bcolor\b'
replacement = "colour"
new_text = re.sub(pattern, replacement, text)
print(f"Texto original: {text}")
print(f"Texto modificado: {new_text}")
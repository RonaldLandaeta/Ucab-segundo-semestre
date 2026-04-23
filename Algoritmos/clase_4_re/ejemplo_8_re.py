"""
Encontrar solo las minúsculas en un texto 
"""
import re

mixed_text = "Hola Mundo!"
lowercase_letters = re.findall('[a-z]', mixed_text)
print(lowercase_letters) 

"""
Extracción de una url desde un texto
"""
import re

text = "Visite nuestro sitio web en https://www.example.com o póngase en contacto con nosotros en info@example.com"
url_pattern = r'https?://\S+'
urls = re.findall(url_pattern, text)
print(urls)
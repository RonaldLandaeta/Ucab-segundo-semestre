"""
Encontrar los códigos de cursos de una universidad
en USA
"""
import re

course_text = "COM101 MAT205 ENG189"
course_codes = re.findall(r'[A-Z]{3}\d{3}', course_text)
print(course_codes)

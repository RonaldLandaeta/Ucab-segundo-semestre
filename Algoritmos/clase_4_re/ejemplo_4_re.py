"""
Suponga que tiene un archivo log que contiene unas líneas como estas:

2024-04-30 10:15: Error: Disk full
2024-04-30 11:30: Info: User logged in

Y queremos extraer los timestamps y mensages usando regex:
"""
import re

log_text = """
2024-04-30 10:15: Error: Disk full
2024-04-30 11:30: Info: User logged in
"""

pattern = r'(\d{4}-\d{2}-\d{2} \d{2}:\d{2}): (.+)'
matches = re.findall(pattern, log_text)

for timestamp, message in matches:
    print(f"Fecha-Hora: {timestamp}, Mensaje: {message}")

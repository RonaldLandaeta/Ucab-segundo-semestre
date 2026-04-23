# Validar una dirección de correo
import re

def validate_email(email):
    pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    return re.match(pattern, email) is not None

# Example usage:
email1 = "user@example.com"
email2 = "invalid-email"
print(f"Es '{email1}' un email válido? {validate_email(email1)}")
print(f"Es '{email2}' un email válido? {validate_email(email2)}")
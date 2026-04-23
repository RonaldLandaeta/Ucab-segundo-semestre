import re

pattern = r'([a-zA-Z0-9._%+-]+)@([a-zA-Z0-9.-]+)\.([a-zA-Z]{2,})'
email = "john.doe@example.com"

match = re.search(pattern, email)
if match:
    username = match.group(1)
    domain = match.group(2)
    tld = match.group(3)
    print(f"Username: {username}, Domain: {domain}, TLD: {tld}")

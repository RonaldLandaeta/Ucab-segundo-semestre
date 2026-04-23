import re

pattern = re.compile(r'hello', re.IGNORECASE)
match = pattern.search("Hello, world!")

print(match)
print(type(match))
print(match.group())
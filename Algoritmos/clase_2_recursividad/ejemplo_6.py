def hanoi(n, source, dest, temp):
    if n == 1:
        print("Mueve un disco de", source, " a ", dest)
    else:
        hanoi(n-1, source, temp, dest)
        print("Mueve un disco de", source, " a ", dest)
        hanoi(n-1, temp, dest, source)

n = 3
source = 1
temp = 2
dest = 3

hanoi(n, source, dest, temp)
filename = input("Enter the filename: ")
with open(filename, 'r') as file:
    for line in file:
        print(line.rstrip()[::-1])

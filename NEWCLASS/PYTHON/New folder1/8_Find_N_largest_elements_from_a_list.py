input_string = input("Enter a string (separated by spaces): ").split()

k = int(input("Enter the length k: "))

input_string.sort()

print(input_string[(k-1)])
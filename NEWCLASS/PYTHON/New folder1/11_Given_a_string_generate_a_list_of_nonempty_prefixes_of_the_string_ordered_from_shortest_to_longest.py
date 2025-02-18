input_string = input("Enter a string: ")

result = []

for i in range(len(input_string)):
    result.append(input_string[:i+1])

print(result)
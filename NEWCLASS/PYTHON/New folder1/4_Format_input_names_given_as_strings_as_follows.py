input_string = input("Enter a string: ")

words = input_string.split()

for i in range(len(words) - 1):
    words[i] = words[i][0]

words = ". ".join(words)

print(words)
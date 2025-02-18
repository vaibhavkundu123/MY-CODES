input_string = input("Enter a string: ").lower().replace(" ", "")

duplicates = []

for char in set(input_string):
    if input_string.count(char) > 1:
        duplicates.append(char)

print("Duplicate characters:", duplicates)

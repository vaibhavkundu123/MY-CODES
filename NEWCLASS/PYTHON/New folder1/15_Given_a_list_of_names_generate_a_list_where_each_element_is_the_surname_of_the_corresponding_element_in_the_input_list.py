input_list = input("Enter a list (separated by commas): ").split(", ")

surnames = []

for name in input_list:
    name = name.split()
    surname = name[-1]
    surnames.append(surname)

print(surnames)
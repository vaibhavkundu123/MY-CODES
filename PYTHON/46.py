def count_letters_case(string):
    return sum(1 for c in string if c.isupper()), sum(1 for c in string if c.islower())

input_string = input("Enter a string: ")
uppercase, lowercase = count_letters_case(input_string)

print(f"Uppercase letters: {uppercase}")
print(f"Lowercase letters: {lowercase}")

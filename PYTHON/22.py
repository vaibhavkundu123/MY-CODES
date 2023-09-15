string = input("Enter a string: ")

reversed_string = ''
for i in range(len(string) - 1, -1, -1):
    reversed_string += string[i]

is_palindrome = string == reversed_string

if is_palindrome:
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")

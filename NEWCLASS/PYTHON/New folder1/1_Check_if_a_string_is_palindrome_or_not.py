string = input("Enter a string: ").lower().replace(" ", "")

reversed_string = ''
for i in range(len(string) - 1, -1, -1):
    reversed_string += string[i]

is_palindrome = string == reversed_string

if is_palindrome:
    print("Palindrome")
else:
    print("Not Palindrome")
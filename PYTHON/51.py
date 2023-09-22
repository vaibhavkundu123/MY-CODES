from palindrome import is_palindrome as p

s = input("Enter a string: ").lower()
if p(s):
    print(f"{s} is a palindrome")
else:
    print(f"{s} is not a palindrome")

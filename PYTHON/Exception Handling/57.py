num = float(input("Enter a number: "))

if num >= 0:
    print("The number is:", num)
else:
    raise ValueError("The number is negative!")

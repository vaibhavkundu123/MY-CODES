num = int(input("Enter the value of num: "))

while num > 0:
    print(num)
    num = num % (10 ** (len(str(num)) - 1))

m = int(input("Enter starting number of the range: "))
n = int(input("Enter ending number of the range: "))
print("Odd numbers are: ")
i = m
while i<n:
    if(i%2 != 0):
        print(i, end=' ')
    i += 1

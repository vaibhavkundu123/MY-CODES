principal = float(input("Enter the principal amount: "))
time = float(input("Enter the time in years: "))

if principal<200000:
    rate = 10
    interest = principal * rate * time / 100
    print(f"The interest amount is {interest}")
elif principal>200000 and principal<1000000:
    rate = 12
    interest = principal * rate * time / 100
    print(f"The interest amount is {interest}")
else:
    rate = 15
    interest = principal * rate * time / 100
    print(f"The interest amount is {interest}")


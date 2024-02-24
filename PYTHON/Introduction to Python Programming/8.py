principal = float(input("Enter the principal amount: "))
rate = float(input("Enter the rate of interest: "))
time = float(input("Enter the time in years: "))

interest = principal * rate * time / 100
total = principal + interest

print(f"The interest amount is {interest}")
print(f"The total amount is {total}")

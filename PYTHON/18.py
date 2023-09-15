lower_limit = int(input("Enter the lower limit: "))
upper_limit = int(input("Enter the upper limit: "))

sum = 0

for number in range (lower_limit, upper_limit + 1):
    is_prime = True

    for i in range(2, int(number ** 0.5) + 1):
        if number % i == 0:
            is_prime = False
            break

    if is_prime:
        sum += number

print(f"The sum of all prime numbers between {lower_limit} and {upper_limit} is {sum}.")

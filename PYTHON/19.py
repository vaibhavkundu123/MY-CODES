prime_count = 0
composite_count = 0

number = int(input("Enter a number: "))

while number != -1:
    is_prime = True 

    for i in range(2, int(number ** 0.5) + 1):
        if number % i == 0:
            is_prime = False
            break

    if is_prime:
        prime_count += 1
    else:
        composite_count += 1

    number = int(input("Enter a number (-1 to exit): "))

print(f"The number of prime numbers entered is {prime_count}.")
print(f"The number of composite numbers entered is {composite_count}.")

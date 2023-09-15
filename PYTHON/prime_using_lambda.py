is_prime = lambda x: all(x % i != 0 for i in range(2, int(x**0.5) + 1)) and x > 1


start_range = int(input("Enter the start of the range: "))
end_range = int(input("Enter the end of the range: "))


prime_numbers = [num for num in range(start_range, end_range + 1) if is_prime(num)]


print(f"Prime numbers between {start_range} and {end_range}: {prime_numbers}")

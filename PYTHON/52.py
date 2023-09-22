from prime import is_prime as p

start = int(input("Enter the start of the range: "))
end = int(input("Enter the end of the range: "))

prime_numbers = [i for i in range(start, end+1) if p(i)]
print(f"Prime numbers between {start} and {end} are {prime_numbers}")

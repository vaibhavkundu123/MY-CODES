start_range, end_range= (int(input("Enter the start of the range: ")), int(input("Enter the end of the range: ")))

print(f"Prime numbers between {start_range} and {end_range}: ", list(filter(lambda x: all(x % i != 0 for i in range(2, int(x**0.5) + 1)) and x > 1, range(start_range, end_range + 1))))

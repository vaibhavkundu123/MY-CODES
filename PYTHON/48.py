start, end = int(input("Enter the start of the range: ")), int(input("Enter the end of the range: "))
print(f"The numbers divisible between {start} and {end} are {list(filter(lambda x: (x % 5 == 0) and (x % 7 == 0), range(start, end+1)))}")

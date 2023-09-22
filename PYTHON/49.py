print("Even numbers in the list:", list(filter(lambda x: x % 2 == 0, [int(x) for x in input("Enter a list of numbers separated by spaces: ").split()])))

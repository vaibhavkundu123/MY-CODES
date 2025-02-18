input_string = input("Enter a string (separated by spaces): ").split()

if input_string == sorted(input_string):
    print("The items in the list are sorted in ascending order.")
elif input_string == sorted(input_string, reverse=True):
    print("The items in the list are sorted in descending order.")
else:
    print("The items in the list are not sorted.")
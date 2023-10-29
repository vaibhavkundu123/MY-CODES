class NegativeAgeError(Exception):
    pass


try:
    age = int(input("Enter your age: "))

    if age < 0:
        raise NegativeAgeError("Age cannot be negative")

    print(f"Your age is {age}")

except ValueError:
    print("Error: Invalid input. Please enter a number.")

except NegativeAgeError as e:
    print(f"Error: {e}")

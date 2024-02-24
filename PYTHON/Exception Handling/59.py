try:
    num = float(input("Enter a number: "))

    square = num ** 2
    print(f"The square of {num} is {square}")

except ValueError:
    print("Error: Invalid input. Please enter a number.")

except KeyboardInterrupt:
    print("\nError: KeyboardInterrupt. You pressed Ctrl + C.")

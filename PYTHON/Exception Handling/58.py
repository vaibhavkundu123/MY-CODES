try:
    num1 = float(input("Enter the first number: "))
    num2 = float(input("Enter the second number: "))

    addition = num1 + num2
    subtraction = num1 - num2
    multiplication = num1 * num2

    if num2 != 0:
        division = num1 / num2
    else:
        division = "Error: Division by zero is not allowed"

    print(f"Addition: {addition}")
    print(f"Subtraction: {subtraction}")
    print(f"Multiplication: {multiplication}")
    print(f"Division: {division}")

except ValueError:
    print("Error: Invalid input. Please enter a number.")

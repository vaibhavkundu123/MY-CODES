def convert_to_decimal(number, base):
    decimal = 0
    power = 0
    while number > 0:
        remainder = number % 10
        decimal += remainder * (base**power)
        power += 1
        number //= 10
    return decimal


def convert_to_other_base(number, base):
    other_base_number = ""
    while number > 0:
        remainder = number % base
        other_base_number += str(remainder)
        number //= base
    return other_base_number[::-1]


def main():

    print("Menu:")
    print("1. Convert from decimal to other base")
    print("2. Convert from other base to decimal")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        number = int(input("Enter the number to convert: "))
        base = int(input("Enter the base to convert the number to: "))

        other_base_number = convert_to_other_base(number, base)
        print(
            "The number {} in base {} is {} in base {}.".format(
                number, 10, other_base_number, base
            )
        )
    elif choice == 2:
        number = input("Enter the number to convert: ")
        base = int(input("Enter the base of the number: "))

        decimal = convert_to_decimal(number, base)
        print(
            "The number {} in base {} is {} in base 10.".format(number, base, decimal)
        )
    else:
        print("Invalid choice.")
        return


if __name__ == "__main__":
    main()

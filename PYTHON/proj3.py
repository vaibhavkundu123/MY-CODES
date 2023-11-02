""" def convert_to_decimal(number, base):
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
"""


def convert_to_decimal(number, base):
    decimal = 0
    power = 0
    while number > 0:
        remainder = number % 10
        decimal += remainder * (base**power)
        power += 1
        number //= 10
    return decimal


def convert_to_other_base(number, base, new_base):
    other_base_number = ""
    while number == 0:
        remainder = number % new_base
        other_base_number += str(remainder)
        number //= new_base
    return other_base_number[::-1]


def print_menu():
    print("Menu:")
    print("1. Convert from decimal to other base")
    print("2. Convert from other base to decimal")
    print("3. Convert from other base to other base")


def get_choice():
    choice = int(input("Enter your choice: "))
    while choice < 1 or choice > 3:
        choice = int(input("Invalid choice.\nPlease enter a valid choice: "))
    return choice


def get_number_to_convert():
    number = input("Enter the number to convert: ")
    return number


def get_base_of_number():
    base = int(input("Enter the base of the number: "))
    while base < 2 or base > 16:
        base = int(input("Invalid base.\nPlease enter a valid base: "))
    return base


def get_new_base():
    new_base = int(input("Enter the base to convert the number to: "))
    while new_base < 2 or new_base > 16:
        new_base = int(input("Invalid base.\nPlease enter a valid base: "))
    return new_base


def main():
    print_menu()
    choice = get_choice()

    if choice == 1:
        number = get_number_to_convert()
        base = get_base_of_number()
        new_base = get_new_base()

        other_base_number = convert_to_other_base(number, base, new_base)
        print("The number {} in base {} is {} in base {}.".format(number, base, other_base_number, new_base))
    elif choice == 2:
        number = get_number_to_convert()
        base = get_base_of_number()

        decimal = convert_to_decimal(number, base)
        print("The number {} in base {} is {} in base 10.".format(number, base, decimal))
    elif choice == 3:
        number = get_number_to_convert()
        base = get_base_of_number()
        new_base = get_new_base()

        other_base_number = convert_to_other_base(number, base, new_base)
        print("The number {} in base {} is {} in base {}.".format(number, base, other_base_number, new_base))


if __name__ == "__main__":
    main()

import random


def generate_secure_password(length):
    uppercase_letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    lowercase_letters = 'abcdefghijklmnopqrstuvwxyz'
    digits = '0123456789'
    special_chars = '!@#$%^&*()_+-=[]{}|;:,.<>?/'

    all_chars = uppercase_letters + lowercase_letters + digits + special_chars

    password = (
        random.choice(uppercase_letters)
        + random.choice(lowercase_letters)
        + random.choice(digits)
        + random.choice(special_chars)
    )

    for _ in range(length - 4):
        password += random.choice(all_chars)

    password_list = list(password)
    random.shuffle(password_list)
    return "".join(password_list)


if __name__ == "__main__":
    try:
        length = int(input("Enter the desired password length (the number should be 4 or more): "))
        secure_password = generate_secure_password(length)
        print("Generated Secure Password:", secure_password)
    except ValueError:
        print("Invalid input. Please enter a valid password length.")

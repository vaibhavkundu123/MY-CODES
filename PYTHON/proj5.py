import random
import string


def generate_secure_password(length):
    if length < 4:
        return "Invalid input. Please enter a valid password length."

    all_chars = string.ascii_letters + string.digits + string.punctuation
    password = random.choice(string.ascii_uppercase)
    password += random.choice(string.ascii_lowercase)
    password += random.choice(string.digits)
    password += random.choice(string.punctuation)
    password += ''.join(random.choice(all_chars) for _ in range(length - 4))

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

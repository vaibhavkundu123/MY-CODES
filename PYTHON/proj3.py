try:
    print("---MENU---\n1. DECIMAL\n2. BINARY\n3. OCTAL\n4. HEXADECIMAL")
    c1 = input("Enter the base you want to enter: ")
    n1 = input("Enter the number: ")
    c2 = input("Enter the base you want to convert to: ")
    if c1 == c2:
        print(n1)
    elif c1 == "1":
        if c2 == "2":
            print(bin(int(n1))[2::])
        elif c2 == "3":
            print(oct(int(n1))[2::])
        elif c2 == "4":
            print(hex(int(n1))[2::].upper())
    elif c1 == "2":
        if c2 == "1":
            print(int(n1, 2))
        elif c2 == "3":
            print(oct(int(n1, 2))[2::])
        elif c2 == "4":
            print(hex(int(n1, 2))[2::].upper())
    elif c1 == "3":
        if c2 == "1":
            print(int(n1, 8))
        elif c2 == "2":
            print(bin(int(n1, 8))[2::])
        elif c2 == "4":
            print(hex(int(n1, 8))[2::].upper())
    elif c1 == "4":
        if c2 == "1":
            print(int(n1, 16))
        elif c2 == "2":
            print(bin(int(n1, 16))[2::])
        elif c2 == "3":
            print(oct(int(n1, 16))[2::])
    else:
        print("Invalid choice")

except Exception as e:
    print("Error occurred:", e)

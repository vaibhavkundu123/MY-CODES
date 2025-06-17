def xor(a, b):
    result = []
    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')
    return ''.join(result)


def div(dividend, divisor):
    l_divisor = len(divisor)
    pick = l_divisor
    tmp = dividend[0: pick]

    while pick < len(dividend):
        if tmp[0] == '1':
            tmp = xor(divisor, tmp) + dividend[pick]
        else:
            tmp = xor('0'*l_divisor, tmp) + dividend[pick]
        pick += 1

    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0'*l_divisor, tmp)

    return tmp


def inputdataword(dataword, divisor):
    #dataword = input("Enter the dataword (binary string): ")
    #divisor = input("Enter the divisor (binary string): ")
    dataword = str(dataword)
    divisor = str(divisor)
    
    l_divisor = len(divisor)
    if l_divisor == 0:
        print("Error: Divisor cannot be empty")
        exit()

    appended_dataword = dataword + '0' * (l_divisor - 1)
    remainder_codeword = div(appended_dataword, divisor)
    codeword = dataword + remainder_codeword

    #print(f"Remainder: {remainder_codeword}")
    #print(f"Encoded Codeword: {codeword}")
    return codeword


def inputcodeword(codeword, divisor):
    #codeword = input("\nEnter the received codeword (binary string): ")
    #divisor = input("Enter the divisor (binary string): ")
    codeword = str(codeword)
    divisor = str(divisor)
    
    l_divisor = len(divisor)

    remainder_codeword = div(codeword, divisor)

    if remainder_codeword == '0' * (l_divisor - 1):
        data_length = len(codeword) - (l_divisor - 1)
        if data_length <= 0:
            print("Invalid codeword: Too short")
        else:
            original_data = codeword[:data_length]
            print("No errors detected. Codeword is valid.")
            print(f"Original Dataword: {original_data}")
    else:
        print("Error detected in the received codeword.")
        print(f"Remainder after division: {remainder_codeword}")

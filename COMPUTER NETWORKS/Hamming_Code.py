def calcRedundantBits(k):
    for i in range(k):
        if 2**i >= k + i + 1:
            return i


def posRedundantBits(dataword, r):
    j = 0
    k = 1
    m = len(dataword)
    res = ""
    for i in range(1, m + r + 1):
        if i == 2**j:
            res = res + "0"
            j += 1
        else:
            res = res + dataword[-1 * k]
            k += 1
    return res[::-1]


def calcParityBits(codeword, r):
    n = len(codeword)
    for i in range(r):
        val = 0
        for j in range(1, n + 1):
            if j & (2**i) == (2**i):
                val = val ^ int(codeword[-1 * j])
        codeword = codeword[: n - (2**i)] + str(val) + codeword[n - (2**i) + 1 :]
    return codeword


def detectError(codeword, r):
    codeword = str(codeword)
    # print(codeword)
    n = len(codeword)
    res = 0
    for i in range(r):
        val = 0
        for j in range(1, n + 1):
            if j & (2**i) == (2**i):
                val = val ^ int(codeword[-1 * j])
        res = res + val * (10**i)
    return int(str(res), 2)


def correctError(codeword, error_pos):
    if error_pos == 0:
        return codeword
    error_index = len(codeword) - error_pos
    corrected_codeword = (
        codeword[:error_index]
        + ("0" if codeword[error_index] == "1" else "1")
        + codeword[error_index + 1 :]
    )
    return corrected_codeword


def extractDataword(codeword, r):
    # print(type(codeword))
    codeword = str(codeword)
    # print(codeword)
    n = len(codeword)
    result = ""
    for i in range(1, n + 1):
        if (i & (i - 1)) != 0:
            result += codeword[-i]
    return result[::-1]


r = 0


def inputdataword(dataword):
    # dataword = input("Enter the data to be transmitted: ")
    dataword = str(dataword)
    # print("Dataword to be transmitted is:", dataword)
    
    k = len(dataword)
    r = calcRedundantBits(k)

    codeword = posRedundantBits(dataword, r)
    codeword = calcParityBits(codeword, r)
    
    # print("Data transferred is:", codeword)
    return codeword


def inputcodeword(received_codeword):
    # received_codeword = input("Enter the received data: ")

    error_pos = detectError(received_codeword, r)

    if error_pos == 0:
        print("No error detected in the received message.")
        corrected_codeword = received_codeword
    else:
        print(
            f"Error detected at position {error_pos}."
        )
        corrected_codeword = correctError(received_codeword, error_pos)
        print("Corrected Codeword:", corrected_codeword)

    final_dataword = extractDataword(corrected_codeword, r)
    print("Extracted Dataword:", final_dataword)

def find_nth_term(n):
    if n % 2 == 0:
        return (3 ** ((n//2) - 1))
    else:
        return (2 ** ((n//2)))


print(find_nth_term(int(input("Enter the number of terms: "))))

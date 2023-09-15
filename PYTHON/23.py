string = input("Enter a string: ")

print(string.replace(string[-1],'*',string.count(string[-1])-1))

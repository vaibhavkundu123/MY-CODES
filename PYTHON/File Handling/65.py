input_file = input("Enter the name of the input file: ")

output_file = input("Enter the name of the output file: ")

with open(input_file, 'r') as file:
    with open(output_file, 'w') as output:
        output.write(file.read()[::-1])

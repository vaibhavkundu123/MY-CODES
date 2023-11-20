input_filename = input("Enter the input filename: ")
output_filename = input("Enter the output filename: ")

with open(input_filename, 'r') as infile, open(output_filename, 'w') as outfile:
    outfile.write(infile.read().upper())

input_filename = input("Enter the input filename: ")
output_filename = input("Enter the output filename: ")

with open(input_filename, 'rb') as infile, open(output_filename, 'wb') as outfile:
    outfile.write(infile.read(100))

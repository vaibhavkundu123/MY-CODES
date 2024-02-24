rows_A = int(input("Enter the number of rows in the first matrix: "))
cols_A = int(input("Enter the number of columns in the first matrix: "))

A = []
print("Enter the elements of the first matrix:")
for i in range(rows_A):
    row = []
    row_input = input().split()
    for element in row_input:
        row.append(int(element))
    A.append(row)

rows_B = int(input("Enter the number of rows in the second matrix: "))
cols_B = int(input("Enter the number of columns in the second matrix: "))

B = []
print("Enter the elements of the second matrix:")
for i in range(rows_B):
    row = []
    row_input = input().split()
    for element in row_input:
        row.append(int(element))
    B.append(row)

if cols_A != rows_B:
    raise ValueError("The number of columns in the first matrix must be equal to the number of rows in the second matrix.")

result = [[0 for j in range(cols_B)] for i in range(rows_A)]

for i in range(rows_A):
    for j in range(cols_B):
        for k in range(cols_A):
            result[i][j] += A[i][k] * B[k][j]

print(f"Resultant Matrix = {result}")

l1=input("Enter the names of employees (separated by a space): ").split()
l2=input("Enter the salaries of employees (separated by a space): ").split()
d={}
for i in range(len(l1)):
    d[l1[i]]=l2[i]
print(d)

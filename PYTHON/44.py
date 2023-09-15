n1=int(input("Enter the no. of pairs for D1: "))
d1={}
d2={}
for i in range(n1):
    key=input("Enter the key: ")
    val=int(input("Enter value: "))
    d1[key]=val
n2=int(input("Enter the no. of pairs for D2: "))
for i in range(n2):
    key=input("Enter the key: ")
    val=int(input("Enter value: "))
    d2[key]=val
for i in d2:
    d1[i]=d2[i]
print(d1)

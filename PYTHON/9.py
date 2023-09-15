a = int(input("Enter 1st number: "))
b = int(input("Enter 2nd number: "))
c = int(input("Enter 3rd number: "))
print("Series in ascending order: ")
if a<b and a<c:
    if b<c:
        print(a,b,c,sep='<')
    else:
        print(a,c,b,sep='<')
elif b<a and b<c:
    if a<c:
        print(b,a,c,sep='<')
    else:
        print(b,c,a,sep='<')
else:
    if(b<a):
        print(c,b,a,sep='<')
    else:
        print(c,a,b,sep='<')

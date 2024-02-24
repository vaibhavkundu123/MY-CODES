n=int(input("Enter the no. of pairs: "))
d={}
temp=[]
for i in range(n):
    key=input("Enter the key: ")
    val=int(input("Enter value: "))
    d[key]=val
lst=list(d.values())
lst.sort()
for i in lst:
    for k in d:
        if d[k]==i:
            if k not in temp:
                temp.append(k)
                print(k,":",i)

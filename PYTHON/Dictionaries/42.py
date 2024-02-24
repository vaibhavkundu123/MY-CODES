n=int(input("Enter the no. of players: "))
cricket={}
for i in range(n):
    name=input("Enter the name: ")
    run=int(input("Enter runs: "))
    cricket[name]=run
name=input("Enter the name you want to search: ")
if name in cricket:
    print(cricket[name])
else:
    print(-1)

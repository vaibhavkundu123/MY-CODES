s1=input("Enter 1st String: ")
s2=input("Enter 2nd String: ")
c=0
if len(s1)!=len(s2):
    print("They are Not Anagrams")
else:
    l1=list(s1)
    l2=list(s2)
    for i in range(len(s1)):
        for j in range(len(s1)):
            if l2[j]==l1[i]:
                c+=1
    if c==len(s1) or s1==s2:
        print("They are Anagrams")
    else:
        print("They are Not Anagrams")

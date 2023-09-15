def unique(l):
    unique_list = []
    duplicate_list = []
    for i in l:
        if i not in unique_list:
            unique_list.append(i)
        elif i in unique_list:
            unique_list.remove(i)
            duplicate_list.append(i)
    return unique_list


l = input("Enter the elements separated by spaces: ").lower().split()
u = unique(l)
print(f"Unique Elements: {u}")
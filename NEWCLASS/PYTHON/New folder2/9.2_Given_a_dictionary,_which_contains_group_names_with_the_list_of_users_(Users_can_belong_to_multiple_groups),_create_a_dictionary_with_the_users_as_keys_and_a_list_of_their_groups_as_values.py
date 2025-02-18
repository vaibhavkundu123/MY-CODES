def create_user_groups(group_dict):
    user_groups = {}
    for group, users in group_dict.items():
        for user in users:
            if user not in user_groups:
                user_groups[user] = []
            user_groups[user].append(group)
    return user_groups


group_dict = {
    "local": ["admin", "Ananya"],
    "public": ["admin", "Zahir"],
    "administrator": ["admin"]
}

user_groups = create_user_groups(group_dict)

print(user_groups)
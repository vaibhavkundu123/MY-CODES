def generate_email_addresses(domain_dict):
    email_addresses = []
    for domain, users in domain_dict.items():
        for user in users:
            email_addresses.append(f"{user}@{domain}")
    return email_addresses


domain_dict = {
    "gmail.com": ["paul.buchheit", "sanjeev.singh", "kevin.fox"],
    "yahoo.com": ["jerry.yang", "david.filo"],
    "hotmail.com": ["sabeer.bhatia"]
}

email_addresses = generate_email_addresses(domain_dict)

print(email_addresses)
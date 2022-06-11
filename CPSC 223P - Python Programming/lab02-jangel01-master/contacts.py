# Name: Jason Angel
# Date: 09/05/21
# Purpose: File contains functions for contacts list to use

def print_list (contacts):
    """Print all the names of the contact list"""

    print("=============== CONTACT LIST ===============")
    print("Index  First Name             Last Name")
    print("====   ==========             ================")

    for i in range(len(contacts)):
        print(f'{str(i):8}{contacts[i][0]:22}{contacts[i][1]:22}')

def add_contact(contacts):
    """Add a mew contact to existing list"""

    firstName = input("Enter the first name: ")
    lastName = input("Enter the last name: ")
    contacts.append([firstName, lastName])
    return contacts

def modify_contact(contacts):
    """Modify any existing contacts"""

    indexNumber = int(input("Enter the index number: "))

    if indexNumber >= len(contacts)  or indexNumber < 0:
        print("Invalid index number.")
        return contacts
    else:
        firstName = input("Enter the first name: ")
        lastName = input("Enter the last name: ")
        contacts[indexNumber] = [firstName,lastName]
        return contacts

def delete_contact(contacts):
    """Delete any existing contact"""

    indexNumber = int(input("Enter the index number: "))

    if indexNumber >= len(contacts) or indexNumber < 0:
        print("Invalid index number.")
        return contacts
    else:
        del contacts[indexNumber]
        return contacts

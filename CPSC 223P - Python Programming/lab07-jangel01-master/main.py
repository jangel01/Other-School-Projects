# Name: Jason Angel
# Date: 10/20/21
# Purpose: Practice using classes

from contacts import *

contacts = Contacts(filename = "default.dat")
choice = 0

while choice != 6:
    print("*** TUFFY TITAN CONTACT MENU")

    print("1. Add contact")
    print("2. Modify contact")
    print("3. Delete contact")
    print("4. Print contact list")
    print("5. Set contact filename")
    print("6. Exit the program")

    choice = int(input("Enter menu choice: "))

    if choice == 1:
        phone_number = input("Enter phone number: ")
        first_name = input("Enter first name: ")
        last_name = input("Enter last name: ")

        result = contacts.add_contact(id = phone_number, first_name = first_name, last_name = last_name)

        if result == "error":
            print(result)
        else:
            print(f'Added: {first_name} {last_name}')
    elif choice == 2:
        phone_number = input("Enter phone number: ")
        first_name = input("Enter first name: ")
        last_name = input("Enter last name: ")

        result = contacts.modify_contact(id = phone_number, first_name = first_name, last_name = last_name)

        if result == "error":
            print(result)
        else:
            print(f'Modified: {first_name} {last_name}')
    elif choice == 3:
        phone_number = input("Enter phone number: ")

        result = contacts.delete_contact(id = phone_number)

        if result == "error":
            print(result)
        else:
            name = result.get(phone_number)
            print(f'Deleted: {name[0]} {name[1]}')
    elif choice == 4:
        print("====================CONTACT LIST====================")
        print("Last Name            First Name           Phone Number")
        print()
        for k, v in contacts.dict.items():
            print(f'{v[1]:<20} {v[0]:<20} {k}')
    elif choice == 5:
        contacts.filename = input("Set filename: ")

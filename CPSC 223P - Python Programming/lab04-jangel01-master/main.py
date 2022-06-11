# Name: Jason Angel
# Date: 9/22/21
# Purpose: Test functions from contacts.py and build a contact dictionary

from contacts import *

contacts = {}
menu_choice = 0

while menu_choice != 6:
    print("*** TUFFY TITAN CONTACT MENU")

    print("1. Add contact")
    print("2. Modify contact")
    print("3. Delete contact")
    print("4. Print contact list")
    print("5. Find contact")
    print("6. Exit the program")

    menu_choice = int(input("Enter choice: "))

    if menu_choice == 1:
        phone_number = int(input("Enter phone number: "))
        first_name = input("Enter first name: ")
        last_name = input("Enter last name: ")

        # Wihile some of these steps may seem unnecessary, it is required for delete_contact()
        # so might as well be consistent in the code
        result = add_contact(contacts, id = phone_number, first_name = first_name, last_name = last_name)
        name = result.get(phone_number)
        print("Added: {fn} {ln}".format(fn = name[0], ln = name[1]))
    elif menu_choice == 2:
        phone_number = int(input("Enter phone number: "))
        first_name = input("Enter first name: ")
        last_name = input("Enter last name: ")

        result = modify_contact(contacts, id = phone_number, first_name = first_name, last_name = last_name)
        name = result.get(phone_number)
        print("Modified: {fn} {ln}".format(fn = name[0], ln = name[1]))
    elif menu_choice == 3:
        phone_number = int(input("Enter phone number: "))

        result = delete_contact(contacts, id = phone_number)
        name = result.get(phone_number)
        print("Deleted: {fn} {ln}".format(fn = name[0], ln = name[1]))
    elif menu_choice == 4:
        sorted_contacts = sort_contacts(contacts)
        print("=============== CONTACT LIST ===============")
        print("Last Name        First Name       Phone     ")
        print("===============  ===============  ==========")

        for k, v in sorted_contacts.items():
            print("{ln}            {fn}            {num}".format(ln = v[1], fn = v[0], num = k))

    elif menu_choice == 5:
        search = input("Enter search string: ")
        found_contacts = find_contact(contacts, find = search)

        print("=============== CONTACT LIST ===============")
        print("Last Name        First Name       Phone     ")
        print("===============  ===============  ==========")

        for k, v in found_contacts.items():
            print("{ln}            {fn}            {num}".format(ln = v[1], fn = v[0], num = k))

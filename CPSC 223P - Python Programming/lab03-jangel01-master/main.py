# Name: Jason Angel
# Date: 9/16/21
# Purpose: FIle executes functions a contact list can use, which can be fonud from contacts.py

from contacts import *

contacts = []

menu_choice = None

while(menu_choice != 7):
    print("         *** TUFFY TITAN CONTACT MENU")
    print("1. Print list")
    print("2. Add contact")
    print("3. Modify contact")
    print("4. Delete contact")
    print("5. Sort list by first name")
    print("6. Sort list by last name")
    print("7. Exit the program")

    menu_choice = int(input("Enter menu choice: "))

    if menu_choice == 1:
        # Print current list
        print("=============== CONTACT LIST ===============")
        print("Index  First Name             Last Name")
        print("====   ==========             ================")

        for i in range(len(contacts)):
            print(f'{str(i):8}{contacts[i][0]:22}{contacts[i][1]:22}')
    elif menu_choice == 2:
        first_name = input("Enter first name: ")
        last_name = input("Enter last name: ")
        add_contact(contacts, first_name = first_name, last_name = last_name)
    elif menu_choice == 3:
        index = int(input("Enter the index number: "))
        first_name = input("Enter first name: ")
        last_name = input("Enter last name: ")
        modify_contact(contacts, index = index, first_name = first_name, last_name = last_name)
    elif menu_choice == 4:
        index = int(input("Enter the index number: "))
        delete_contact(contacts, index = index)
    elif menu_choice == 5:
        sort_contacts(contacts, column = 0)
    elif menu_choice == 6:
        sort_contacts(contacts, column = 1)

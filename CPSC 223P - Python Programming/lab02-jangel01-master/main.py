# Name: Jason Angel
# Date: 09/05/21
# Purpose: FIle creates an enoty list which is used on the functions found in contacts.py.

from contacts import *

contacts = []

menu_choice = 0

while(menu_choice != 5):
    print("*** TUFFY TITAN CONTACT MENU")

    print("1. Print List")
    print("2. Add contact")
    print("3. Modify contact")
    print("4. Delete contact")
    print("5. Exit the program")

    menu_choice = int(input("Enter menu choice: "))

    if(menu_choice == 1):
        print_list(contacts)
    elif(menu_choice == 2):
        contacts = add_contact(contacts)
    elif(menu_choice == 3):
        contacts = modify_contact(contacts)
    elif(menu_choice == 4):
        contacts = delete_contact(contacts)

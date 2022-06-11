# Name: Jason Angel
# Date: 9/16/21
# Purpose: FIle contains functions a contact list can utilize.

def add_contact(contacts, /, *, first_name, last_name):
    """ Add name to contact list """

    contacts.append([first_name, last_name])

def modify_contact(contacts, /, *, index, first_name, last_name):
    """ Modify a contact in current list """

    if index >= 0 and index < len(contacts):
        contacts[index] = [first_name, last_name]
        return True
    else:
        print("Invalid index number.")
        return False

def delete_contact(contacts, /, *, index):
    """ Delete a contact in current list """

    if index >= 0 and index < len(contacts):
        del contacts[index]
        return True
    else:
        print("Invalid index number.")
        return False

def sort_contacts(contacts, /, *, column):
    """ Sort list by first name or last name """

    if (column == 0):
        contacts.sort()
    else:
        contacts.sort(key = lambda contact: contact[1])

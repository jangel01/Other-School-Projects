# Name: Jason Angel
# Date: 09/22/21
# Purpose: FIle contaitns functions for contact dictionary to call

def add_contact(contacts, /, *, id, first_name, last_name):
    """ Add contact to dictionary """

    if id in contacts:
        return "error"

    contacts[id] = [first_name, last_name]

    #Return key:value pair of the added contact
    return {id : [first_name, last_name]}

def modify_contact(contacts, /, *, id, first_name, last_name):
    """ Modify any existing contact in the dictionary """

    if id not in contacts:
        return "error"

    contacts[id] = [first_name, last_name]

    # Return key:value pair of the modified contact
    return {id : [first_name, last_name]}

def delete_contact(contacts, /, *, id):
    """ Delete any existng contact in the dictionary """

    if id not in contacts:
        return "error"

    # Retrieve the value before deleting the contact
    value = contacts.get(id)

    del contacts[id]

    # Return key:value pair of the deleted contact
    return {id : value}

def sort_contacts(contacts, /):
    """ Sort contact list by last name and then by first name """

    # Sort new dictionary by last name
    new_dict = dict(sorted(contacts.items(), key = lambda x: x[1][1].lower()))

    # Re-sort dictionary by first name
    new_dict = dict(sorted(new_dict.items(), key = lambda x: x[1][0].lower()))

    return new_dict

def find_contact(contacts, /, *, find):
    """ Find and collect contacts that match the specified search string """

    new_dict = {}

    if find.isnumeric():                          # See whether search string is a phone number
        # Search string is a phone number, so convert search string into an integer
        # Rename variables to avoid confusion
        key = int(find)
        value = contacts.get(key)

        if key != None:
            new_dict[key] = value
    else:                                         # Check to see if search string is a substring of a contact
        for key, value in contacts.items():
            # value is a list, so it can be looped
            for name in value:
                if find.lower() in name.lower():
                    new_dict[key] = value


    new_dict = sort_contacts(new_dict)

    return new_dict

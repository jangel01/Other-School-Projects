import unittest
import io
import sys
from unittest.mock import patch

from contacts import *

class Test01_AddContact(unittest.TestCase):
    def test_list_int(self):
        """
        *** Test01 *** Calling the 'add_contact' method passing a positional argument equal to [['Richard','Stallman']], a keyword argument first_name equal to 'Steve', and a keyword argument last_name equal to 'Jobs' should result in a contact list [['Richard','Stallman'],['Steve','Jobs']] ***
        """
        contacts = [["Richard","Stallman"]]
        add_contact(contacts, first_name = "Steve", last_name = "Jobs")
        self.assertEqual(contacts, [['Richard', 'Stallman'], ['Steve', 'Jobs']])
        print()

class Test02_ModifyContact(unittest.TestCase):
    def test_list_int(self):
        """
        *** Test02 *** Calling the 'modify_contact' method passing a positional argument equal to [['Richard','Stallman'],['Bill','Gates']], a keyword argument first_name equal to 'Steve', a keyword argument last_name equal to 'Jobs', and a keyword argument index equal to '1' should result in a contact list [['Richard','Stallman'],['Steve','Jobs']] ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"]]
        modify_contact(contacts, index = 1, first_name = "Steve", last_name = "Jobs")
        self.assertEqual(contacts, [['Richard', 'Stallman'], ['Steve', 'Jobs']])
        print()

class Test03_ModifyContact(unittest.TestCase):
    def test_list_int(self):
        """
        *** Test03 *** Calling the 'modify_contact' method passing a positional argument equal to [['Richard','Stallman'], a keyword argument first_name equal to 'Steve', a keyword argument last_name equal to 'Jobs', and a keyword argument index equal to '5' should result in a contact list [['Richard','Stallman']] and a return value of False ***
        """
        contacts = [["Richard","Stallman"]]
        x = modify_contact(contacts, index = 5, first_name = "Steve", last_name = "Jobs")
        self.assertEqual(contacts, [['Richard', 'Stallman']])
        self.assertEqual(x, False)
        print()

class Test04_DeleteContact(unittest.TestCase):
    def test_list_int(self):
        """
        *** Test04 *** Calling the 'delete_contact' method passing a positional argument equal to [['Richard','Stallman'],['Bill','Gates'],['Steve','Jobs']], and a keyword argument index equal to '1' should result in a contact list [['Richard','Stallman'],['Steve','Jobs']] ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"],["Steve","Jobs"]]
        delete_contact(contacts, index = 1)
        self.assertEqual(contacts, [['Richard', 'Stallman'], ['Steve', 'Jobs']])
        print()

class Test05_DeleteContact(unittest.TestCase):
    def test_list_int(self):
        """
        *** Test05 *** Calling the 'delete_contact' method passing a positional argument equal to [['Richard','Stallman'],['Steve','Jobs']], and a keyword argument index equal to '5' should result in a contact list [['Richard','Stallman'],['Steve','Jobs']] and a return value of False ***
        """
        contacts = [["Richard","Stallman"],["Steve","Jobs"]]
        x = delete_contact(contacts, index = 5)
        self.assertEqual(contacts, [['Richard', 'Stallman'], ['Steve', 'Jobs']])
        self.assertEqual(x, False)
        print()

class Test06_SortContacts(unittest.TestCase):
    def test_list_int(self):
        """
        *** Test06 *** Calling the 'sort_contacts' method passing a positional argument equal to [['Richard','Stallman'],['Bill','Gates'],['Steve','Jobs']], and a keyword argument column equal to '0' should result in a contact list [['Bill','Gates'], ['Richard', 'Stallman'], ['Steve', 'Jobs']] ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"],["Steve","Jobs"]]
        sort_contacts(contacts, column = 0)
        self.assertEqual(contacts, [['Bill','Gates'], ['Richard', 'Stallman'], ['Steve', 'Jobs']])
        print()

class Test07_SortContacts(unittest.TestCase):
    def test_list_int(self):
        """
        *** Test07 *** Calling the 'sort_contacts' method passing a positional argument equal to [['Richard','Stallman'],['Bill','Gates'],['Steve','Jobs']], and a keyword argument column equal to '1' should result in a contact list [['Bill', 'Gates'], ['Steve', 'Jobs'], ['Richard', 'Stallman']] ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"],["Steve","Jobs"]]
        sort_contacts(contacts, column = 1)
        self.assertEqual(contacts, [['Bill', 'Gates'], ['Steve', 'Jobs'], ['Richard', 'Stallman']])
        print()

if __name__ == '__main__':
    with open('test.txt', "w") as f:
        runner = unittest.TextTestRunner(f)
        unittest.main(testRunner=runner)

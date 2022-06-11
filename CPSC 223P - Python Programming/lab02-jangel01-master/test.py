import unittest
import io
import sys
from unittest.mock import patch

from contacts import *

class Test01_AddContact(unittest.TestCase):
    @patch("builtins.input", side_effect=["Steve","Jobs"])
    def test_list_int(self, mock_input):
        """
        *** Test01 *** Calling the 'add_contact' method passing a contact list [['Richard','Stallman']] and adding the contact ['Steve','Jobs'] should return [['Richard','Stallman'],['Steve','Jobs']] ***
        """
        contacts = [["Richard","Stallman"]]
        result = add_contact(contacts)
        self.assertEqual(result, [['Richard', 'Stallman'], ['Steve', 'Jobs']])

class Test02_ModifyContact(unittest.TestCase):
    @patch("builtins.input", side_effect=[1,"Steve","Jobs"])
    def test_list_int(self, mock_input):
        """
        *** Test02 *** Calling the 'modify_contact' method passing a contact list [['Richard','Stallman'],['Bill','Gates']] and modifing the contact at index 1 with ['Steve','Jobs'] should return [['Richard','Stallman'],['Steve','Jobs']] ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"]]
        result = modify_contact(contacts)
        self.assertEqual(result, [['Richard', 'Stallman'], ['Steve', 'Jobs']])

class Test03_ModifyContact(unittest.TestCase):
    @patch("builtins.input", side_effect=[3])
    def test_list_int(self, mock_input):
        """
        *** Test03 *** Calling the 'modify_contact' method passing a contact list [['Richard','Stallman'],['Steve','Jobs']] and modifing the contact at index 3 shoud return 'Invalid index number.' ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"]]
        capturedOutput = io.StringIO()
        sys.stdout = capturedOutput
        result = modify_contact(contacts)
        sys.stdout = sys.__stdout__
        self.assertEqual(capturedOutput.getvalue().replace("\n",""), "Invalid index number.")
        print()

class Test04_DeleteContact(unittest.TestCase):
    @patch("builtins.input", side_effect=[1])
    def test_list_int(self, mock_input):
        """
        *** Test04 *** Calling the 'delete_contact' method passing a contact list [['Richard','Stallman'],['Bill','Gates'],['Steve','Jobs']] and deleting the contact at index 1 should return [['Richard','Stallman'],['Steve','Jobs']] ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"],["Steve","Jobs"]]
        result = delete_contact(contacts)
        self.assertEqual(result, [['Richard', 'Stallman'], ['Steve', 'Jobs']])

class Test05_DeleteContact(unittest.TestCase):
    @patch("builtins.input", side_effect=[3])
    def test_list_int(self, mock_input):
        """
        *** Test05 *** Calling the 'delete_contact' method passing a contact list [['Richard','Stallman'],['Steve','Jobs']] and deleting the contact at index 3 shoud return 'Invalid index number.' ***
        """
        contacts = [["Richard","Stallman"],["Bill","Gates"]]
        capturedOutput = io.StringIO()
        sys.stdout = capturedOutput
        result = modify_contact(contacts)
        sys.stdout = sys.__stdout__
        self.assertEqual(capturedOutput.getvalue().replace("\n",""), "Invalid index number.")
        print()

if __name__ == '__main__':
    with open('test.txt', "w") as f:
        runner = unittest.TextTestRunner(f)
        unittest.main(testRunner=runner)

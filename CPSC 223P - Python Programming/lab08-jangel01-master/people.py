# Name: Jason Angel
# Date: 10/28/21
# Purpose: Module practices inhertiance of classes.

class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname

class Faculty(Person):
    def __init__(self, firstname, lastname, department):
        super().__init__(firstname, lastname)
        self.department = department

class Student(Person):
    def __init__(self, firstname, lastname):
        super().__init__(firstname, lastname)
        self.classyear = None
        self.major = None
        self.advisor = None

    def set_class(self, classyear):
        self.classyear = classyear

    def set_major(self, major):
        self.major = major

    def set_advisor(self, faculty):
        self.advisor = faculty

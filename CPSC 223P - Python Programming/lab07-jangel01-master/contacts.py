# Name: Jason Angel
# Date: 10/20/21
# Purpose: File contains contacts class

import json
from json.decoder import JSONDecodeError

class Contacts:
  def __init__(self,*, filename):
    self.filename = filename
    self.dict = {}
    try:
      with open(self.filename, 'r') as f:
        self.dict = json.load(f)
    except FileNotFoundError:
      print("File does not exist")
    except JSONDecodeError:           # Deal with empty files
      pass

  def add_contact(self, *, id, first_name, last_name):
    """Add a contact to dict and write it to to .dat file"""
    if id in self.dict:
      return "error"

    self.dict[id] = [first_name, last_name]

    self.dict = dict(sorted(self.dict.items(), key = lambda x : x[1][1].lower()))
    self.dict = dict(sorted(self.dict.items(), key = lambda x : x[1][0].lower()))

    with open(self.filename, 'w') as f:
        json.dump(self.dict, f)

    return {id : [first_name, last_name]}

  def modify_contact(self, *, id, first_name, last_name):
     """Modify a contact from dict and rewrite .dat file"""
     if id not in self.dict:
         return "error"

     self.dict[id] = [first_name, last_name]

     self.dict = dict(sorted(self.dict.items(), key = lambda x : x[1][1].lower()))
     self.dict = dict(sorted(self.dict.items(), key = lambda x : x[1][0].lower()))

     with open(self.filename, 'w') as f:
         json.dump(self.dict, f)

     return {id : [first_name, last_name]}

  def delete_contact(self, *, id):
      """Delete a contact from dict and rewrite .dat file"""
      if id not in self.dict:
          return "error"

      value = tuple(self.dict.get(id))
      del self.dict[id]

      with open(self.filename, 'w') as f:
          json.dump(self.dict, f)

      return {id : value}

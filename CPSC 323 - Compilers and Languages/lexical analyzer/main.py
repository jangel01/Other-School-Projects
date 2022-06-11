import csv
import os.path
from lexer import Lexer

scanning_file = "scanning_table.csv"
token_file = "token_table.csv"
reserved_file = 'reserved_table.csv'
source_code = "test1.txt"
file_list = [scanning_file, token_file, reserved_file, source_code]

def choose_file_paths(file_list):
    number = None
    while number != 5:
        print("Which file path would you like to modify?")
        print('''
        1. Scanning file
        2. Token file
        3. Reserved file
        4. Source code file
        5. Exit
        ''')
        number = int(input(">> "))
        if number == 1:
            file_list[0] = input("Input scanning file path: ")
        elif number == 2:
            file_list[1] = input("Input token file path: ")
        elif number == 3:
            file_list[2] = input("Input reserved file path: ")
        elif number == 4:
            file_list[3] = input("Input source code file path: ")
        elif number == 5:
            break

def file_path_exists(file_list):
    for file in file_list:
        if os.path.isfile(file) == False:
            print(f'{file} does not point to a file. Ending program.')
            exit(0)


def verify_csv(file_list):
    for file in file_list:
        if len(file) < 5 or file[-4:] != ".csv":
            print(f' {file} is not in csv format. Ending program.')
            exit(0)


print("Would you like to modify any file paths?")
print('''
        1. Yes
        2  No
''')
number = int(input(">> "))
if number == 1:
    choose_file_paths(file_list)

file_path_exists(file_list)

verify_csv(file_list[0:3])

lexer = Lexer(file_list)

tokens = lexer.perform_analysis()

print("Press enter to request tokens. Enter any other key to stop requesting.")
"""Will continuously print the lexemes until invalid input"""
stop_token_request = False
for t in tokens:
    response = input()
    if response == "":
        if t[1] in lexer.token_dict or t[1] == "keyword":
            print(f'Token: {t[1]:>12}   Lexeme: {t[0]}')
        else:
            print(f'Error message: {t}')
    else:
        stop_token_request = True
        break

if stop_token_request == False:
    print("Reached end of token stream. Ending program.")
else:
    print("Stopped token request. Ending program.")

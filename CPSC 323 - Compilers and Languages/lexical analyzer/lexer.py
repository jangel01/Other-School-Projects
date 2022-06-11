
import csv

class Lexer:
    def __init__(self, files):
        self.scanning_file = str(files[0])
        self.token_file = str(files[1])
        self.reserved_file = str(files[2])
        self.source_file = str(files[3])
        self.test = None
        self.scanning_dict = {}
        self.token_dict = {}
        self.reserved_list = []

        self.populate()

    def perform_analysis(self):
        self.current_token = 0
        tokens = []
        black_list = ["whitespace", "comment"]

        while self.current_token < len(self.test):
            token = self.get_token()
            if token[1] in black_list:
                continue
            tokens.append(token)

        return tokens

    def populate(self):
        with open(self.scanning_file, 'r') as sf, open(self.token_file, 'r') as tf, open(self.reserved_file,
          'r') as rf, open(self.source_file, 'r') as sc:
            scanning_reader = csv.reader(sf)
            token_reader = csv.reader(tf)
            reserved_reader = csv.reader(rf)
            self.test = sc.read()

            for row in token_reader:
                if row[0] in self.token_dict:
                    existing_list = self.token_dict.get(row[0])
                    existing_list.append(int(row[1]))
                    self.token_dict[row[0]] = existing_list
                else:
                    new_list = [int(row[1])]
                    self.token_dict[row[0]] = new_list

            for row in reserved_reader:
                self.reserved_list.append(row[0])

            column_names = []
            column_names_exist = False
            for row in scanning_reader:
                if column_names_exist == False:
                    for col in row:
                        column_names.append(col)

                    sf.seek(0)
                    next(sf)
                    column_names_exist = True
                    continue

                temp_dict = {}

                for i in range(1, len(column_names)):
                    x = row[i]
                    if x == '':
                        x = None
                    else:
                        x = int(x)
                    temp_dict[column_names[i]] = x

                self.scanning_dict[int(row[0])] = temp_dict

    def get_token(self):
        remembered_chars = ""
        current_state = 0
        image = ""
        remembered_state = 0

        while True:
            current_character = self.get_character()
            action = self.choose_action(current_state, current_character)

            if action == 0:
                if current_state in self.scanning_dict.keys() and any(current_state in d for d in self.token_dict.values()):
                    remembered_state = current_state
                    remembered_chars = ""

                remembered_chars += current_character
                current_state = self.scanning_dict[current_state][current_character]
            elif action == 1:
                for k, v in self.token_dict.items():
                    if current_state in v:
                        token = k
                        break
                if not self.current_token == len(self.test):
                    self.current_token -= 1
                break
            else:
                if remembered_state != 0:
                    for k, v in self.token_dict.items():
                        if remembered_state in v:
                            token = k
                            break
                    self.current_token -= len(remembered_chars)
                    image = image[:-len(remembered_chars)]
                    break
                return "error at lexeme number: " + str(self.current_token) + " | current lexeme: " + str(current_character) + " | current state: " + str(current_state) + " | remembered state: " + str(remembered_state)

            if current_character == '0x20':
                current_character = ' '
            image += current_character

        token_tuple = (image, token)
        token_tuple = self.keyword_check(token_tuple)
        return token_tuple

    def choose_action(self, current_state, current_character):
        if current_state in self.scanning_dict.keys() and current_character in self.scanning_dict[current_state].keys():
            move = self.scanning_dict[current_state][current_character]

            if move is not None:
                return 0

        if any(current_state in d for d in self.token_dict.values()):
            return 1

        return 2

    def get_character(self):
        if self.current_token < len(self.test):
            char = self.test[self.current_token]
            self.current_token += 1

            if char == '\t':
                char = '0x09'
            elif char == '\b':
                char = '0x08'
            elif char == '\n':
                char = '0x0a'
            elif char == '\r':
                char = '0x09'
            elif char == ' ':
                char = '0x20'

            return char
        else:
            self.current_token += 1
            return 0

    def keyword_check(self,token_tuple):
        if token_tuple[1] == 'identifier' and token_tuple[0] in self.reserved_list:
            return token_tuple[0], "keyword"
        
        return token_tuple

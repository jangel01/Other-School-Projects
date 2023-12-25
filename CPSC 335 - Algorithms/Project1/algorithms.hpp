///////////////////////////////////////////////////////////////////////////////
// algorithms.hpp
//
// Definitions for four algorithms:
//
// run_length_encode
// longest_frequent_substring
// reformat_date
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <map>
#include <ctime>
#include <list>
#include <vector>

namespace algorithms {

  // Run-length-encode the given string.
  //
  // uncompressed must be a string containing only lower-case letters or spaces.
  //
  // A run is defined as a sequence of K>2 contiguous copies of the same
  // character c.
  // For example, "aaa" is a run with K=3 and c='a'.
  // This function returns a string based on uncompressed, where every run is
  // replaced with the string
  //   COUNTc
  // where COUNT is the base-10 representation of K. Non-run characters are
  // left as-is.
  //
  // Example inputs and outputs:
  //   "aaa" -> "3a"
  //   "heloooooooo there" -> "hel8o there"
  //   "footloose and fancy free" -> "f2otl2ose and fancy fr2e"
  //
  // Throws std::invalid_argument if the string contains invalid characters.


  void append_run(std::string &C, char &run_char, int &run_length)
  {
    if (run_length > 1)
    {
      C = C + std::to_string(run_length);
    }

    C = C + run_char;
  }


  std::string run_length_encode(const std::string& uncompressed) {


    std::string C = "";

    if (uncompressed.empty()) {
      return C;
    }

    for (int i = 0; i < uncompressed.size(); i++) {
      if (std::isspace(uncompressed[i]) == false && std::isalpha(uncompressed[i]) == false) {
        throw std::invalid_argument("Invalid character detected");
      }

      if (std::isspace(uncompressed[i]) == false && std::islower(uncompressed[i]) == false) {
        throw std::invalid_argument("Uppercase letter detected");
      }
    }

    char run_char = uncompressed[0];
    int run_length = 1;

    for (int i = 1; i < uncompressed.size(); i++) {
      if (uncompressed[i] == run_char) {
        run_length++;
      } else {
        append_run(C, run_char, run_length);
        run_char = uncompressed[i];
        run_length = 1;
      }
    }

    append_run(C, run_char, run_length);
    return C;

  }

  // Returns the longest substring of text, such that every character in the
  // substring appears at least k times in text.
  // If there are ties, the substring that appears first is returned.
  std::string longest_frequent_substring(const std::string& text, unsigned k) {

    if (text.empty() || k > text.size())
    {
      return "";
    }

    if (k == 1) {
      return text;
    }

    std::map<char, int> freq;

    for (char c : text) {
      if (freq.find(c) == freq.end()) {
        freq[c] = 1;
      } else {
        freq[c] += 1;
      }
    }


    std::string best = "";

    for (int b = 0; b < text.size() - 1; b++)
    {

      for (int e = b + 1; e <= text.size(); e++) {

        bool invalid = false;
        std::string cand = text.substr(b, e - b);

        for (char c : cand) {

          if (freq[c] >= k) {
            continue;
          } else {
            invalid = true;
            break;
          }
        }

        if (invalid == false && cand.size() > best.size()) {
          best = cand;
        }
      }
    }

    return best;



  }

  // Reformats a string containing a date into YYYY-MM-DD format.
  //
  // input may be formatted in one of four patterns:
  // 1. Y-M-D
  //    where Y, M, and D are positive integers
  // 2. M/D/Y
  //    where Y, M, and D are positive integers
  // 3. MONTH DAY, YEAR
  //    where
  //    - MONTH is a case-insensitive name of a month, ex.
  //      "january", "FEBRUARY", "March", etc.
  //    - DAY is a positive integer representing a day, e.x. "15"
  //    - YEAR is a positive integer representing a year, e.x. "2022"
  // 4. MON DAY, YEAR
  //    where
  //    - MON is a case-insensitive three-letter abbreviation of a month, ex.
  //      "jan", "FEB", "Mar", etc.
  //    - DAY is the same as above
  //    - YEAR is the same as above
  //
  // Any leading spaces or trailing spaces are ignored.
  //
  // Returns a string in strict YYYY-MM-DD format.
  //
  // Throws std::invalid argument if:
  // - input does not fit any of the four patterns
  // - MONTH is not a valid month name
  // - MON is not a valid month abbreviation
  // - DAY is not in the range [1, 31]
  // - YEAR is not in the range [1900, 2099]

  void parseString(std::vector<std::string> &test_date_vars, std::string &str, char delim) {
    std::string field = "";

    for (auto it = str.begin(); it != str.end(); ++it) {
      if (*it == delim || it == str.end() -1) {
        if (it == str.end() -1) {
          field = field + *it;
        }
        test_date_vars.push_back(field);
        field = "";
      } else {
        field = field + *it;
      }
    }
  }

  void convertStringToLower(std::string &str) {
    for (int i = 0; i < str.size(); i++) {
      str[i] = tolower(str[i]);
    }
  }

  void date_int_validation(std::string &str) {
    for (char c : str) {
      if (!isdigit(c)) {
        throw std::invalid_argument("field with illegal character detected.");
      }
    }
  }

  void date_validation(std::vector<std::string> &valid_date_vars, std::vector<std::string> &test_date_vars, std::vector<int> &pos_map) {
    if(isalpha(test_date_vars[pos_map[1]][0])) {
      std::vector<std::string> months{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

      convertStringToLower(test_date_vars[pos_map[1]]);

      int month_num = 1;
      for (auto it = months.begin(); it != months.end(); it++, month_num++) {
        convertStringToLower(*it);

        if (it->find(test_date_vars[pos_map[1]]) != std::string::npos)
        {
          if (test_date_vars[pos_map[1]].size() == 3 || it->size() == test_date_vars[pos_map[1]].size()) {
            valid_date_vars[1] = std::to_string(month_num);
            break;
          }
        }
      }

      if (valid_date_vars[1].empty()) {
        throw std::invalid_argument("month field not valid");
      }
    } else {

      date_int_validation(test_date_vars[pos_map[1]]);
      int m_int = std::stoi(test_date_vars[pos_map[1]]);
      if (m_int < 1 || m_int > 12) {
        throw std::invalid_argument("month is out of range");
      } else {
        valid_date_vars[1] = test_date_vars[pos_map[1]];
      }
    }

    date_int_validation(test_date_vars[pos_map[0]]);
    int y_int = std::stoi(test_date_vars[pos_map[0]]);
    if (y_int < 1900 || y_int > 2099) {
      throw std::invalid_argument("year is out of range");
    } else {
      valid_date_vars[0] = test_date_vars[pos_map[0]];
    }

    date_int_validation(test_date_vars[pos_map[2]]);
    int d_int = std::stoi(test_date_vars[pos_map[2]]);
    if(d_int < 1 || d_int > 31) {
      throw std::invalid_argument("day is out of range");
    } else {
      valid_date_vars[2] = test_date_vars[pos_map[2]];
    }
  }

  std::string reformat_date(const std::string& input) {
    // vector<year, month, day>, contains string variables to be validated
    std::vector<std::string> test_date_vars;

    std::string newString = "";

    // Handle leading and trailing whitespace contained in input
    std::string WHITESPACE = " \r\n\t\v\f";
    auto start = input.find_first_not_of(WHITESPACE);
    auto end = input.find_last_not_of(WHITESPACE);

    newString = start == end ? "" : input.substr(start, end - start + 1);


    // Parse the input depending on the date format
    if (newString.find('-') != std::string::npos)
    {
      parseString(test_date_vars, newString, '-');
    }
    else if (newString.find('/') != std::string::npos)
    {
      parseString(test_date_vars, newString, '/');
    }
    else if (newString.find(' ') != std::string::npos)
    {
      newString.erase(std::remove(newString.begin(), newString.end(), ','), newString.end());
      parseString(test_date_vars, newString, ' ');
    }
    else
    {
      throw std::invalid_argument("no valid separator detected.");
    }

    // validate amount of fields
    if (test_date_vars.size() > 3) {
      throw std::invalid_argument("too many field(s) detected");
    } else if (test_date_vars.size() < 3) {
      throw std::invalid_argument("missing field(s) detected");
    }

    // validate fields to see if they actually contain content
    if (test_date_vars[0] == "" || test_date_vars[1] == "" || test_date_vars[2] == "") {
      throw std::invalid_argument("empty field(s) detected.");
    }

    // vector<year, month, day>, same layout as std::vector test_date_vars
    // Vector contains valid content that will later be concatenated to a single string
    std::vector<std::string> valid_date_vars{"", "", ""};
    // index positions of string date variables for std::vector test_date_vars, which depends on the date format.
    std::vector<int> pos_map{-1, -1, -1};

    if (isalpha(test_date_vars[0][0])) // Format: "MONTH D, Y" or "MON D, Y"
    {
      pos_map[0] = 2, pos_map[1] = 0, pos_map[2] = 1;
      date_validation(valid_date_vars, test_date_vars, pos_map);
    }
    else if (isdigit(test_date_vars[0][0])) // Format: "M/D/Y"
    {
      if (test_date_vars[0].size() == 1 || test_date_vars[0].size() == 2) {
        pos_map[0] = 2, pos_map[1] = 0, pos_map[2] = 1;
        date_validation(valid_date_vars, test_date_vars, pos_map);
      }
      else if (test_date_vars[0].size() == 4) // Format: "Y-M-D"
      {
        pos_map[0] = 0, pos_map[1] = 1, pos_map[2] = 2;
        date_validation(valid_date_vars, test_date_vars, pos_map);
      }
      else
      {
        throw std::invalid_argument("first field does not yield a month or year type");
      }
    }
    else
    {
      throw std::invalid_argument("date is not suitable to start any comparisons.");
    }


    // Zero pad if necessary
    if (valid_date_vars[2].size() == 1) {
      valid_date_vars[2].insert(valid_date_vars[2].begin(), '0');
    }
    if (valid_date_vars[1].size() == 1) {
      valid_date_vars[1].insert(valid_date_vars[1].begin(), '0');
    }

    std::string date = valid_date_vars[0] + '-' + valid_date_vars[1] + '-' + valid_date_vars[2];

    return date;
  }
}

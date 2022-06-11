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

// TODO: Add any additional #include directives that you need.
// After you do that, delete this comment.

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
  std::string run_length_encode(const std::string& uncompressed) {

    // TODO: Rewrite the body of this function so that it actually works. That
    // includes rewriting the return statement. After you do that, delete this
    // comment.
    return "";
  }

  // Returns the longest substring of text, such that every character in the
  // substring appears at least k times in text.
  // If there are ties, the substring that appears first is returned.
  std::string longest_frequent_substring(const std::string& text, unsigned k) {

    // TODO: Rewrite the body of this function so that it actually works. That
    // includes rewriting the return statement. After you do that, delete this
    // comment.
    return "";
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
  std::string reformat_date(const std::string& input) {

    // TODO: Rewrite the body of this function so that it actually works. That
    // includes rewriting the return statement. After you do that, delete this
    // comment.
    return "";
  }

}

///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives


#include <cstddef>
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Book.hpp"
#include "BookDatabase.hpp"


/////////////////////// END-TO-DO (1) ////////////////////////////



// Return a reference to the one and only instance of the database
BookDatabase & BookDatabase::instance()
{
  std::string filename;

  // Look for a prioritized list of database files in the current working directory to use
  // Don't forget to #include <filesystem> to get visibility to the exists() function
  if     ( filename = "Open Library Database-Full.dat"  ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Open Library Database-Large.dat" ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Open Library Database-Medium.dat";   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Open Library Database-Small.dat" ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Sample_Book_Database.dat"        ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else     filename.clear();

  static BookDatabase theInstance( filename );
  return theInstance;
}




// Construction
BookDatabase::BookDatabase( const std::string & filename )
{
  std::ifstream fin( filename, std::ios::binary );


  ///////////////////////// TO-DO (2) //////////////////////////////
    /// The file contains Books separated by whitespace.  A Book has 4 pieces of data delimited with a comma.  (This exactly matches
    /// the previous assignment as to how Books are read)
    ///
    ///       Field            Type            Notes
    ///  1.   Book's ISBN      String          Unique identifier (primary key), always enclosed in double quotes
    ///  2.   Book's Title     String          May contain spaces, always enclosed in double quotes
    ///  3.   Book's Author    String          May contain spaces, always enclosed in double quotes
    ///  4.   Book's Price     Floating Point  In dollars
    ///
    ///  Example:
    ///    "0001062417",  "Early aircraft",                 "Maurice F. Allward", 65.65
    ///    "0000255406",  "Shadow maker \"1st edition)\"",  "Rosemary Sullivan",   8.08
    ///    "0000385264",  "Der Karawanenkardinal",          "Heinz Gstrein",      35.18
    ///
    ///  Note: double quotes within the string are escaped with the backslash character
    ///

  // Most of the work is already delegated in the book class, all that is needed is to read the file (aka reading books)
  // and pushing the content into a vector
  Book book;
  while (fin >> book) {
    _books_vector.emplace_back( std::make_unique<Book>( std::move( book ) ) );
  }


  /////////////////////// END-TO-DO (2) ////////////////////////////

  // Note:  The file is intentionally not explicitly closed.  The file is closed when fin goes out of scope - for whatever
  //        reason.  More precisely, the object named "fin" is destroyed when it goes out of scope and the file is closed in the
  //        destructor. See RAII
}


///////////////////////// TO-DO (3) //////////////////////////////
  /// Implement the rest of the interface, including functions find (recursively) and size
  ///

Book * BookDatabase::find( const std::string & isbn ) {
  return find( isbn, 0);
}

Book * BookDatabase::find(const std::string &isbn, size_t index) {
  // Base case - reached end of list with no matching isbn
  if(index == size()) {
    return nullptr;
  }

  // Vist - check whether isbn matches
  if (_books_vector[index]->isbn() == isbn) {
    // return raw pointer
    return _books_vector[index].get();
  }

  // Recurse - isbn didn't match, increment index to see if the next position's isbn does
  return find( isbn, ++index );
}

std::size_t BookDatabase::size() const {
  return _books_vector.size();
}

/// Programming note:  An O(n) operation, like searching an unsorted vector, would not generally be implemented recursively.  The
///                    depth of recursion may be greater than the program's function call stack size.  But for this programming
///                    exercise, getting familiar with recursion is a goal.

/////////////////////// END-TO-DO (3) ////////////////////////////

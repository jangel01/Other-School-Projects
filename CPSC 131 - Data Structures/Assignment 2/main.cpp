#include <exception>
#include <iostream>
#include <typeinfo>

#include "Book.hpp"
#include "BookList.hpp"




namespace
{
  void basicScenario()
  {
    // Let's start a book list
    BookList booksToRead = {{"Inviable Man"           },
                            {"Moby Dick"              },
                            {"Les Mis"                },
                            {"A Tale of Two Cities"   }};

    // Changed my mind, I want to make sure I read Les Mis first so I'm going to move that to the top of my list
    booksToRead.moveToTop( {"Les Mis"} );

    // Let's see what's on the list so far
    std::cout << "My Book List" << booksToRead << "\n\n";

    // Yay, no.  Need to add a few more
    booksToRead += {{"Ulysses"          },
                    {"The Color Purple" }};


    // My roommate also has a book list
    BookList roommatesList = {{"Hunger Games", "S. Collins"               },
                              {"Hunger Games", "Suzanne Collins"          },
                              {"Les Mis"                                  },
                              {"Secret Garden", "Frances Hodgson Burnett" },
                              {"Charlie & Choc Factory"                   }};

    std::cout << "My roommate's Book List" << roommatesList << "\n\n";

    // Let's combine the lists (if different) and go shopping
    if( booksToRead != roommatesList ) booksToRead += roommatesList;

    // Oops, forgot one of my favorites.  Let's add that right before '2 cities.
    booksToRead.insert( {"Oliver Twist", "Charles Dickens"}, booksToRead.find( {"A Tale of Two Cities"} ) );

    // Time is short, let me take one off the list!
    booksToRead.remove({"Secret Garden", "Frances Hodgson Burnett"});

    // Now let's see what's on the list
    std::cout << "Combined Book Lists" << booksToRead << "\n\n";



    // Did you get it right?
    BookList expectedResults = {{"Les Mis"                         },
                                {"Inviable Man"                    },
                                {"Moby Dick"                       },
                                {"Oliver Twist", "Charles Dickens" },
                                {"A Tale of Two Cities"            },
                                {"Ulysses"                         },
                                {"The Color Purple"                },
                                {"Hunger Games", "S. Collins"      },
                                {"Hunger Games", "Suzanne Collins" },
                                {"Charlie & Choc Factory"          }};

    std::cout << "\nExpected results:" << expectedResults                                        << "\n\n"
              << "\nActual results:"   << booksToRead                                            << "\n\n"
              << "\nTest results:  "   << ( booksToRead == expectedResults  ? "PASS"  :  "FAIL") << '\n';
  }
}




int main()
{
  try
  {
    basicScenario();


    ///////////////////////// TO-DO (1) //////////////////////////////
     /// Create, manipulate, and display your own BookList object here.  Not looking for anything specific but expect you to write
     /// about 15 to 20 C++ lines of code (not necessarily physical lines in this file) that demonstrate you can use the BookList
     /// class to create, update, and display the contents of a book list.

    std::cout << std::string(40, '#') << "\n";

    // create first book list
    BookList bookList1 = {{"The Great Gatsby", " F.Scott Fitzgerald"},
                        {"The Catcher in the Rye", "J. D. Salinger"},
                        {"The Cat in the Hat", "Dr. Seuss"},
                        {"The Road", "Cormac McCarthy"},
                        {"Diary of a Wimpy Kid", "Jeff Kinney"}};

    std::cout << "First book list (initial): " << bookList1 << "\n\n";

    bookList1.moveToTop({"The Catcher in the Rye", "J. D. Salinger"});

    // insert new book before "The Road"
    bookList1.insert({"Starting Out with C++ 9th edition", "Tony Gaddis"}, bookList1.find({"The Road", "Cormac McCarthy"}));

    bookList1.remove({"Diary of a Wimpy Kid", "Jeff Kinney"});

    std::cout << "First book list (modified): " << bookList1 << "\n\n";

    // create second book list
    BookList bookList2 = {{"To Kill a Mocking Bird", "Harper Lee"},
                          {"Of Mice and Men", "John Steinbeck"},
                          {"Lord of the Flies", "William Golding"},
                          {"Night", "Elie Wiesel"}};

    std::cout << "Second book list: " << bookList2 << "\n\n";

    // compare booklist1 with booklist2
    if(bookList1.compare(bookList2) == -1) {
      std::cout << "---First book list is less than the second--- \n\n";
    } else if (bookList1.compare(bookList2) == 1) {
      std::cout << "---First book list is greater than the second--- \n\n";
    } else {
      std::cout << "---First and second book list are equal--- \n\n";
    }

    // combine booklist1 and booklist2 if they aren't equal, duplicates will be ignored
    if(bookList1 != bookList2) {
      bookList1 += bookList2;
    }

    std::cout << "First and second book list combined: " << bookList1 << "\n\n";

    /////////////////////// END-TO-DO (1) ////////////////////////////
  }

  catch( const std::exception & ex )
  {
    std::cerr << "Fatal Error:  unhanded exception \"" << typeid( ex ).name() << "\"\n"
              << ex.what() << '\n';
  }
}

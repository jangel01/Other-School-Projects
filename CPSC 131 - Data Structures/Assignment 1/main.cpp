#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include "Book.hpp"

int main() {
  // fix price to two decimal places
  std::cout << std::setprecision(2) << std::fixed;
  // vector contains pointers to book objects
  std::vector<Book *> books;
  Book book;

  // welcome message
  std::cout << "Welcome to Forgotten Books, a bookstore filled with books from all nations. ";
  std::cout << "Place books into your shopping cart by entering each book's information." << std::endl;
  std::cout << "   Enclose string entries in quotes, separate fields with comas" << std::endl;
  std::cout << "   Enter CTL-Z(Windows) or CTL-D(Linux) to quit" << std::endl;
  std::cout << std::endl;

  // read a book from cin, loop doesn't stop until user terminates the program
  while (std::cout << "Enter ISBN, Title, Author, and Price:" << std::endl, std::cin >> book) {
      // store book into dynamically allocated object
      books.push_back(new Book(std::move(book)));

      std::cout << "Item added to shopping cart: " << *books.back() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Here is an itemized list of the items in your shopping cart:" << std::endl;
  // print information of books in reverse order
  for (int i = books.size(); i > 0; i--) {
    std::cout << *books[i - 1] << std::endl;

    // release memory
    delete books[i - 1];
  }

    return 0;
}

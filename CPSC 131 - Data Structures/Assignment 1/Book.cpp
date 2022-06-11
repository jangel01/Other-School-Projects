#include "Book.hpp"
#include <string>
#include <iomanip>
#include <string_view>
#include <cmath>

// class constructor
Book::Book(std::string_view isbn, std::string_view title, std::string_view author, double price)
    : _isbn(isbn), _title(title), _author(author), _price(price) {}

// mutators (setters)
void Book::isbn(std::string_view newIsbn) {
  _isbn = newIsbn;
}

void Book::title(std::string_view newTitle) {
  _title = newTitle;
}

void Book::author(std::string_view newAuthor) {
  _author = newAuthor;
}

void Book::price(double newPrice){
  _price = newPrice;
}

// queries (getters)
std::string Book::isbn() const {
  return _isbn;
}

std::string Book::title() const {
  return _title;
}

std::string Book::author() const {
  return _author;
}

double Book::price() const {
  return _price;
}

// insertion(>>) overloading
std::istream &operator>>(std::istream &stream, Book &book) {
  Book workingItem;
  char delimiter = ',';

  // read book attributes and store it in workingItem object
  stream >> std::quoted(workingItem._isbn) >> delimiter
  >> std::quoted(workingItem._title) >> delimiter
  >> std::quoted(workingItem._author) >> delimiter
  >> workingItem._price;

  // if book attributes are valid, copy workingItem object to book object
  if (stream) {
    book = workingItem;
  }

  return stream;
}

// extraction(<<) overloading
std::ostream &operator<<(std::ostream &stream, const Book &book) {
  const std::string delimiter = ", ";

  // write book attributes to standard output
  stream << std::quoted(book.isbn()) << delimiter
  << std::quoted(book.title()) << delimiter
  << std::quoted(book.author()) << delimiter
  << book.price();

  return stream;
}

// relational operators overloading
bool operator==(const Book &lhs, const Book &rhs) {
  double epsilon = 0.0001;

  if (lhs._isbn == rhs._isbn &&
      lhs._title == rhs._title &&
      lhs._author == rhs._author &&
      std::abs(lhs._price - rhs._price) < epsilon) {
    return true;
  }
  else {
    return false;
  }
}

bool operator<(const Book &lhs, const Book &rhs) {
  double epsilon = 0.0001;

  if(lhs._isbn.length() >= rhs._isbn.length()) {
    return false;
  }
  if(lhs._title.length() >= rhs._title.length()) {
    return false;
  }
  if(lhs._author.length() >= rhs._author.length()) {
    return false;
  }
  if(std::abs(lhs._price - rhs._price) >= epsilon) {
    return lhs._price < rhs._price;
  }
  return true;
}

bool operator!=(const Book &lhs, const Book &rhs) {
  return !(lhs == rhs);
}

bool operator<=(const Book &lhs, const Book &rhs) {
  return !(rhs < lhs);
}

bool operator>(const Book &lhs, const Book &rhs) {
  return (rhs < lhs);
}

bool operator>=(const Book &lhs, const Book &rhs) {
  return !(lhs < rhs);
}

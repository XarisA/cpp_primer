#ifndef BOOK_OBJ
#define BOOK_OBJ

#include <string>
#include <iostream>

class Book {
    friend std::ostream &operator<<(std::ostream&, const Book&);
    friend std::istream &operator>>(std::istream&, Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
public:
    Book(std::string n, double p) : name(n), price(p) {};
    Book() : name(""), price(0.0) {};
private:
    std::string name;
    double price;
};

#endif
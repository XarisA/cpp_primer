#ifndef BOOK_OBJ
#define BOOK_OBJ

#include <string>
#include <iostream>

class Book {
    friend std::ostream &operator<<(std::ostream&, const Book&);
    friend std::istream &operator>>(std::istream&, const Book&);
public:
    Book(std::string n, double p) : name(n), price(p) {};
private:
    std::string name;
    double price;
};

#endif
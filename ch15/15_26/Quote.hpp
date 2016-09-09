#ifndef QUOTE
#define QUOTE

#include <string>
#include <iostream>

class Quote {
public:
    Quote() : bookNo(""), price(0.0) {
        std::cout << "Quote()" << std::endl;
    }

    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {
        std::cout << "Quote(const std::string &book, double sales_price)" << std::endl;
    }
    
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote(const Quote &q)" << std::endl;
    }

    Quote& operator=(const Quote &rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;
        std::cout << "Quote& operator=(const Quote &rhs)" << std::endl;
        return *this;
    }
    
    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug() const { std::cout << bookNo << ' ' << price; }

    virtual ~Quote() {
        std::cout << "virtual ~Quote()" << std::endl;
    }
private:
    std::string bookNo;
protected:
    double price;
};

#endif
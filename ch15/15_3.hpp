#ifndef QUOTE
#define QUOTE

#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug() const { std::cout << bookNo << ' ' << price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

#endif
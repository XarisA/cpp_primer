#ifndef QUOTE
#define QUOTE

#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;

    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
    
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) { }

    Quote& operator=(const Quote &rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    
    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug() const { std::cout << bookNo << ' ' << price; }

    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }

    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price;
};

#endif
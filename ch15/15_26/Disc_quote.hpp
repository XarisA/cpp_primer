#ifndef DISC_QUOTE
#define DISC_QUOTE

#include "Quote.hpp"
#include <string>

class Disc_quote : public Quote {
public:
    Disc_quote() : Quote(), quantity(0), discount(0.0) {
        std::cout << "Disc_quote()" << std::endl;
    }

    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
                Quote(book, price), quantity(qty), discount(disc) { 
        std::cout << "Disc_quote(const std::string &book, double price, std::size_t qty, double disc)" << std::endl;
    }
    
    Disc_quote(const Disc_quote &q) : Quote(q), quantity(q.quantity), discount(q.discount) {
        std::cout << "Disc_quote(const Disc_quote &q)" << std::endl;
    }

    Disc_quote& operator=(const Disc_quote &rhs) {
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        std::cout << "Disc_quote& operator=(const Disc_quote &rhs)" << std::endl;
        return *this;
    }

    double net_price(std::size_t) const = 0;

    ~Disc_quote() {
        std::cout << "~Disc_quote()" << std::endl;
    }
protected:
    std::size_t quantity;
    double discount;
};

#endif
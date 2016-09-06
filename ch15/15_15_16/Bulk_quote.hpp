#ifndef BULK_QUOTE
#define BULK_QUOTE

#include "Disc_quote.hpp"
#include <string>

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
                Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t n) const override {
        if (n >= quantity) {
            return price * discount * n;
        }
        else {
            return price * n;
        }
    }
};

#endif
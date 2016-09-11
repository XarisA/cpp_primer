#ifndef BULK_QUOTE
#define BULK_QUOTE

#include "Disc_quote.hpp"
#include <string>

class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
                Disc_quote(book, price, qty, disc) { }

    Bulk_quote(const Bulk_quote &q) : Disc_quote(q) { }

    Bulk_quote& operator=(const Bulk_quote &rhs) {
        Disc_quote::operator=(rhs);
        std::cout << "Bulk_quote& operator=(const Bulk_quote &rhs)" << std::endl;
        return *this;
    }

    double net_price(std::size_t n) const override {
        if (n >= quantity) {
            return price * discount * n;
        }
        else {
            return price * n;
        }
    }

    Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }

    ~Bulk_quote() = default;
};

#endif
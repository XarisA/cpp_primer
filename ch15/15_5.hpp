#ifndef BULK_QUOTE
#define BULK_QUOTE

#include "15_3.hpp"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &s, double p, std::size_t qty, double disc) : Quote(s, p), min_qty(qty), discount(disc) {}

    double net_price(std::size_t n) const override {
        if (n >= min_qty) {
            return price * (1 - discount) * n;
        }
        else {
            return price * n;
        }
    }
private:
    std::size_t min_qty;
    double discount;
};

#endif
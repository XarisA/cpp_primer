#ifndef LIMITED_DISCOUNT_QUOTE
#define LIMITED_DISCOUNT_QUOTE

#include "Disc_quote.hpp"

class Limited_quote : public Disc_quote {
public:
    Limited_quote() = default;
    Limited_quote(const std::string &s, double p, std::size_t qty, double disc) :
                 Disc_quote(s, p, qty, disc) { }

    double net_price(std::size_t n) const override {
        if (n > quantity) {
            return price * discount * quantity + price * (n - quantity);
        }
        else {
            return price * discount * n;
        }
    }
};

#endif
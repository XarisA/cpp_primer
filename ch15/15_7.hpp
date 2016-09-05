#ifndef LIMITED_DISCOUNT_QUOTE
#define LIMITED_DISCOUNT_QUOTE

#include "15_3.hpp"

class Limited_quote : public Quote {
public:
    Limited_quote() = default;
    Limited_quote(const std::string &s, double p, std::size_t qty, double disc) : Quote(s, p), max_qty(qty), discount(disc) {}

    double net_price(std::size_t n) const override {
        if (n > max_qty) {
            return price * discount * limit + price * (n - limit)
        }
        else {
            return price * discount * n;
        }
    }
private:
    std::size_t max_qty;
    double discount;
};

#endif
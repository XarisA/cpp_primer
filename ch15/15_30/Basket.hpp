#ifndef BASKET
#define BASKET

#include "Bulk_quote.hpp"
#include <set>

double print_total(std::ostream &os, const Quote &q, const std::size_t n) {
    double total = q.net_price(n);
    os << "ISBN: " << q.isbn()
    << "\nNumber of items: " << n
    << "\nTotal: " << total << std::endl;
    return total;
}

class Basket {
public:
    double total_receipt(std::ostream&) const;

    void add_item(const Quote &sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }

    void add_item(const Quote &&sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale.clone())));
    }

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}


#endif

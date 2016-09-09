#include "15_15_16/Bulk_quote.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::shared_ptr<Quote>> bucket;
    bucket.push_back(std::make_shared<Bulk_quote>("0-111-999-01", 5.2, 10, .51));
    bucket.push_back(std::make_shared<Bulk_quote>("0-111-999-02", 15.3, 70, .25));
    bucket.push_back(std::make_shared<Bulk_quote>("0-111-999-03", 2.1, 10, .15));
    bucket.push_back(std::make_shared<Bulk_quote>("0-111-999-04", 77, 8, 0.5));
    bucket.push_back(std::make_shared<Bulk_quote>("0-111-999-05", 125, 12, 0.5));

    double total;
    for (const auto p : bucket) {
        total += p->net_price(10);
    }
    std::cout << total << std::endl;
    
    return 0;
}
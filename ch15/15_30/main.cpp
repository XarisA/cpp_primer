#include <iostream>
#include "Basket.hpp"

int main() {
    Basket basket;
    Bulk_quote  b1("0-111-999-01", 5.2, 10, .51),
                b2("0-111-999-01", 5.2, 10, .55),
                b3("0-111-999-02", 15.3, 70, .25),
                b4("0-111-999-02", 15.3, 70, .25),
                b5("0-111-999-03", 1.0, 1, 1.0);
    
    basket.add_item(b1);
    basket.add_item(b2);
    basket.add_item(b3);
    basket.add_item(b4);
    basket.add_item(b5);

    double sum = 0.0;
    sum = basket.total_receipt(std::cout);
    
    return 0;
}
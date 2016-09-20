#include "../ch14/14_6_9.hpp"
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_multiset<Sales_data> us;
    us.insert(Sales_data("100-0000-01", 10, 6.6));
    us.insert(Sales_data("100-0000-01", 10, 6.6));
    us.insert(Sales_data("100-0000-00", 8, 6.2));
    us.insert(Sales_data("100-0000-01", 15, 6.6));

    for (const auto &s : us) {
        std::cout << s << std::endl;
    }

    return 0;
}
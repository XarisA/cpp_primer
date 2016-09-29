#include "../ch14/14_6_9.hpp"       // Sales_data header
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
    std::vector<Sales_data> vs;
    vs.push_back(Sales_data("11111", 1, 15));
    vs.push_back(Sales_data("11111", 2, 15));
    vs.push_back(Sales_data("11111", 10, 11));
    vs.push_back(Sales_data("11111", 10, 1));
    vs.push_back(Sales_data("11111", 11, 15));

    auto fcn = std::mem_fn(&Sales_data::avg_price);
    auto it = std::find_first_of(vs.cbegin(), vs.cend(), fcn > 100);

    if (it != vs.cend()) {
        std::cout << *it << std::endl;
    }

    return 0;
}
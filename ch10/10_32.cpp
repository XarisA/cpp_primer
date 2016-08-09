#include "../include/Sales_item.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

int main() {
    std::vector<Sales_item> items;
    std::istream_iterator<Sales_item> in_iter(std::cin), eof;
    while (in_iter != eof) {
        items.push_back(*in_iter++);
    }

    std::sort(items.begin(), items.end(), compareIsbn);

    // Credit for this loop: pezy/CppPrimer/ex10_32.cpp
    for (auto beg = items.cbegin(), end = beg; beg != items.cend(); beg = end) {
        end = std::find_if(beg, items.cend(), [beg](const Sales_item &item){ return item.isbn() != beg->isbn(); });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << std::endl;
    }   
}
#include "../ch07/7_41.hpp"
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

// ex 10.12
bool compareIsbn(const Sales_data &d1, const Sales_data &d2) {
    return d1.isbn() < d2.isbn();
}

int main() {
    vector<Sales_data> sales;
    sales.emplace_back("123");
    sales.emplace_back("32512");
    sales.emplace_back("13453");
    sales.emplace_back("213432");
    sales.emplace_back("2314");
    sales.emplace_back("375");
    sales.emplace_back("0971023");
    sales.emplace_back("198247234");
    sales.emplace_back("123");
    sales.emplace_back("124");
    
    //sort(sales.begin(), sales.end(), compareIsbn);
    // ex 10.17 : lambda version
    sort(sales.begin(), sales.end(), [](const Sales_data &d1, const Sales_data &d2) { return d1.isbn() < d2.isbn(); } );
    for (const auto &s : sales) {
        cout << s.isbn() << ' ';
    }
    cout << endl;

    return 0;
}
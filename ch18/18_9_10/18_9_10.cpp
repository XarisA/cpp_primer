#include "my_exceptions.hpp"
#include "../../ch14/14_6_9.hpp"       // Sales_data header

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &s1, const Sales_data &s2) {
    Sales_data sum = s1;
    sum += s2;
    return sum;
}

std::istream& operator>>(std::istream &is, Sales_data &s) {
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    if (is)     s.revenue = s.units_sold * price;
    else        s = Sales_data();
    return is;
}

int main() {
    Sales_data item1, item2, sum;
    while (std::cin >> item1 >> item2) {
        try {
            sum = item1 + item2;
            std::cout << sum << std::endl;
        } catch (const isbn_mismatch &e) {
            std::cerr << e.what() << ": left isbn(" << e.left
                    << ") right isbn(" << e.right << ")" << std::endl;
        }
    }

    // ex 18.10 :
    // terminating with uncaught exception of type isbn_mismatch: wrong isbns
    //
    // while (std::cin >> item1 >> item2) {
    //     sum = item1 + item2;
    //     std::cout << sum << std::endl;
    // }

    return 0;
}
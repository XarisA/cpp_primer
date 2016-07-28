#include <iostream>

using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data& combine(const Sales_data &rhs);
    string isbn() const;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

string Sales_data::isbn() const {
    return bookNo;
}

istream &read(istream &is, Sales_data &s) {
    is >> s.bookNo >> s.units_sold >> s.revenue;
    return is;
}

ostream &print(ostream &os, const Sales_data &s) {
    os << s.bookNo << ' ' << s.units_sold << ' ' << s.revenue;
    return os;
}

Sales_data add(const Sales_data &s1, const Sales_data &s2) {
    Sales_data result;
    result.bookNo = s1.bookNo;
    result.units_sold = s1.units_sold + s2.units_sold;
    result.revenue = s1.revenue + s2.revenue;
    return result;
}

int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else {
        cerr << "No data?!" << endl;
    }
    return 0;
}
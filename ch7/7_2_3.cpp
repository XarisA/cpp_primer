#include <iostream>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;
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

int main() {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                cout << total.isbn() << ' ' << total.units_sold << ' ' << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.isbn() << ' ' << total.units_sold << ' ' << total.revenue << endl;
    }
    else {
        cerr << "No data?!" << endl;
    }
    return 0;
}
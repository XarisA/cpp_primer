#ifndef SALES_DATA_OBJ
#define SALES_DATA_OBJ
#include <iostream>

using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Sales_data {
    friend istream &read(istream &is, Sales_data &s);
    friend ostream &print(ostream &os, const Sales_data &s);
    friend Sales_data add(const Sales_data &s1, const Sales_data &s2);
    
    private:
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    public:
        Sales_data& combine(const Sales_data &rhs);
        string isbn() const;
        inline double avg_price();

        // constructors
        Sales_data(const string &s, unsigned u, double r) : 
                    bookNo(s), units_sold(u), revenue(r * u) {
            #ifndef NDEBUG
            std::cerr << "Delegate called"<< endl;
            #endif
        }
        Sales_data() : Sales_data("", 0, 0.0) {
            #ifndef NDEBUG
            std::cerr << "Default constructor called"<< endl;
            #endif
        }
        Sales_data(const string &s) : Sales_data(s, 0, 0.0) {
            #ifndef NDEBUG
            std::cerr << "string constructor called"<< endl;
            #endif
        }
        
        Sales_data(istream &is) : Sales_data("", 0, 0.0){
            #ifndef NDEBUG
            std::cerr << "istream constructor called"<< endl;
            #endif
            read(is, *this);
        }   
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

string Sales_data::isbn() const {
    return bookNo;
}

double Sales_data::avg_price() {
    return revenue / units_sold;
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

#endif
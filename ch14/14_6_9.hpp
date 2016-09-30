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
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend istream& operator>>(istream&, Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend Sales_data add(const Sales_data &s1, const Sales_data &s2);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend class std::hash<Sales_data>;
    
    private:
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    public:
        Sales_data& combine(const Sales_data &rhs);
        Sales_data& operator+=(const Sales_data&);
        Sales_data& operator=(const string&);
        Sales_data& operator=(const Sales_data&);
        string isbn() const;
        inline double avg_price();
        explicit operator string() const { return bookNo; }
        explicit operator double() const { return revenue; }

        // constructors
        Sales_data(const string &s, unsigned u, double r) : 
                    bookNo(s), units_sold(u), revenue(r * u) {
            // #ifndef NDEBUG
            // std::cerr << "Delegate called"<< endl;
            // #endif
        }
        Sales_data() : Sales_data("", 0, 0.0) {
            // #ifndef NDEBUG
            // std::cerr << "Default constructor called"<< endl;
            // #endif
        }
        Sales_data(const string &s) : Sales_data(s, 0, 0.0) {
            // #ifndef NDEBUG
            // std::cerr << "string constructor called"<< endl;
            // #endif
        }
        
        Sales_data(istream &is) : Sales_data("", 0, 0.0){
            // #ifndef NDEBUG
            // std::cerr << "istream constructor called"<< endl;
            // #endif
            read(is, *this);
        }

        Sales_data(const Sales_data &s) : Sales_data(s.bookNo,
                                         s.units_sold, s.revenue) { }  
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data& Sales_data::operator=(const Sales_data &s) {
    if (*this == s) return *this;
    bookNo = s.bookNo;
    units_sold = s.units_sold;
    revenue = s.revenue;
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

ostream& operator<<(ostream &os, const Sales_data &s) {
    return print(os, s);
}

Sales_data add(const Sales_data &s1, const Sales_data &s2) {
    Sales_data result;
    result.bookNo = s1.bookNo;
    result.units_sold = s1.units_sold + s2.units_sold;
    result.revenue = s1.revenue + s2.revenue;
    return result;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold &&
            lhs.revenue == rhs.revenue;
}

namespace std {
    template <>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &s) const;
    };

    size_t hash<Sales_data>::operator()(const Sales_data &s) const {
        return hash<string>()(s.bookNo) ^
                hash<unsigned>()(s.units_sold) ^
                hash<double>()(s.revenue);
    }
}

#endif
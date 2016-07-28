#include "7_21.hpp"

int main() {
    Sales_data  s1 = Sales_data(), 
                s2 = Sales_data("123456"), 
                s3 = Sales_data("12346", 5, 25.6);
    Sales_data s_in = Sales_data(cin);
    print(cout, s1) << endl;
    print(cout, s2) << endl;
    print(cout, s3) << endl;
    print(cout, s_in) << endl;
    return 0;
}
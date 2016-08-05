#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::ofstream;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(int argc, char** argv) {
    Sales_data total;
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::app);
    if (in) {
        if (in >> total.bookNo >> total.units_sold >> total.revenue) {
            Sales_data trans;
            while (in >> trans.bookNo >> trans.units_sold >> trans.revenue) {
                if (total.bookNo == trans.bookNo) {
                    total.units_sold += trans.units_sold;
                    total.revenue += trans.revenue;
                }
                else {
                    out << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << endl;
                    total = trans;
                }
            }
            out << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << endl;
        }
        else {
            cerr << "No data?!" << endl;
        }
    }
    else {
        cerr << "File failed to open!" << endl;
    }
    
    return 0;
}
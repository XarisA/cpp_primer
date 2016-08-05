#include <iostream>

using std::cout;
using std::endl;
using std::string;

class myDate{
    private:
        unsigned year, month, day;
    public:
        myDate(const string &s) {
            unsigned format = 0;
            
            if (s.find_first_of('/') != string::npos) {     //  1/1/1990
                format = 0x01;
            }
            else if (s.find_first_of(',') > 4 && s.find_first_of(',') != string::npos) {        // January 1, 1990 or Jan 1, 1990
                format = 0x10;
            }
            else if (s.find_first_of(' ') >= 3 && s.find_first_of(' ') != string::npos) {       // Jan 1 1990 or January 1 1990
                format = 0x10;
            }
            else {      // 1 1 1990
                format = 0x11;
            }

            switch(format) {
                case 0x01:
                    month = stoi(s);
                    day = stoi(s.substr(s.find_first_of('/') + 1));
                    year = stoi(s.substr(s.find_last_of('/') + 1));
                    break;
                case 0x10:
                    if( s.find("Jan") < s.size() )  month = 1;
                    if( s.find("Feb") < s.size() )  month = 2;
                    if( s.find("Mar") < s.size() )  month = 3;
                    if( s.find("Apr") < s.size() )  month = 4;
                    if( s.find("May") < s.size() )  month = 5;
                    if( s.find("Jun") < s.size() )  month = 6;
                    if( s.find("Jul") < s.size() )  month = 7;
                    if( s.find("Aug") < s.size() )  month = 8;
                    if( s.find("Sep") < s.size() )  month = 9;
                    if( s.find("Oct") < s.size() )  month = 10;
                    if( s.find("Nov") < s.size() )  month = 11;
                    if( s.find("Dec") < s.size() )  month = 12;
                    day = stoi(s.substr(s.find_first_of(' ') + 1));
                    year = stoi(s.substr(s.find_last_of(", ") + 1));
                    break;
                case 0x11:
                    month = stoi(s);
                    day = stoi(s.substr(s.find_first_of(' ') + 1));
                    year = stoi(s.substr(s.find_last_of(' ') + 1));
            }
        }
        void print() {
            cout << month << '/' << day << '/' << year << endl;
        }
};

int main() {
    myDate d1("Jan 1 2011"), d2("January 1 2011"), d3("01 01 2011"), 
        d4("Jan 1, 2011"), d5("January 1,2011"), d6("January 1, 2011"), 
        d7("1/1/2011"), d8("01/01/2011"), d9("1/01/2011"), d0("01/1/2011");
        d0.print();
        d1.print();
        d2.print();
        d3.print();
        d4.print();
        d5.print();
        d6.print();
        d7.print();
        d8.print();
        d9.print();

        return 0;
}


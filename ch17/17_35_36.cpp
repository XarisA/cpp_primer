#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double d = 100 * sqrt(2.0);
    cout << "default format: " << d << "\n"
        << "scientific: " << scientific << d << "\n"
        << "fixed decimal: " << fixed << d << "\n"
        << "hexadecimal: " << hexfloat << d << "\n"
        << "use defaults: " << defaultfloat << d << "\n"
        << "uppercase hex: " << uppercase << hexfloat << d << "\n"
        << nouppercase << defaultfloat << "\n";

    double e = sqrt(3.0), f = -sqrt(12.5);
    cout << "d: " << setw(12) << d << " next col" << "\n"
        << "e: " << setw(12) << e << " next col" << "\n"
        << "f: " << setw(12) << f << " next col" << "\n";
    
    return 0;
}

#include <memory>

int main() {
    std::unique_ptr<double> p1(new double(3.0));        // OK
    std::unique_ptr<double> p2(p1);                     // ERROR
    std::unique_ptr<double> p3;
    p3 = p1;                                            // ERROR

    return 0;
}
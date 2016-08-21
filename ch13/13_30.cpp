#include "13_30.hpp"

int main() {
    HasPtr p1("p1"), p2("p2");
    swap(p1, p2);
    p1.show();
    p2.show();
    return 0;
}
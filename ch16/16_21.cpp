#include <iostream>

class DebugDelete {
public:
    DebugDelete() = default;
    template <typename T>
    void operator()(T *t) const {
        std::cout << "deleting unique_ptr..." << std::endl;
        delete t;
    }
};

int main() {
    double *p = new double;
    DebugDelete d;
    d(p);
    
    return 0;
}
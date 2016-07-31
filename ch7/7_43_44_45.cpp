#include <vector>

class NoDefault {
    private:
        int i;
    public:
        NoDefault(int n) : i(n) {};
};

class C {
    private:
        NoDefault nd;
    public:
        C() : nd(0) {};
};

int main() {
    //std::vector<NoDefault> vec(10);       // error: no default constructor
    std::vector<C> vec2(10);                // OK
    return 0;
}
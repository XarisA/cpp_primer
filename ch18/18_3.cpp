#include <memory>
#include <vector>
#include <fstream>

struct int_array {
    int_array() : p(nullptr) { }
    explicit int_array(size_t size) : p(new int[size]) { }
    ~int_array() { delete[] p; }

    int *p;
};

void ecercise(int *b, int *e) {
    std::vector<int> v(b, e);
    // int *p = new int[v.size()];      // old approach

    int_array ia(v.size());             // approach 1

    std::shared_ptr<int> p(new int[v.size()], [](int *p){ delete[] p; });
                                        // approach 2
    std::ifstream in("ints");
    // exception occurs here
}

int main() {

}
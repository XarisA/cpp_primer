#include <iostream>
#include <fstream>

class isInRange {
public:
    isInRange(size_t low, size_t up) : lower(low), upper(up) {}
    bool operator()(const std::string &s) const { return s.size() <= upper && s.size() >= lower; }
private:
    size_t lower;
    size_t upper;
};

int main(int argc, char** argv) {
    std::ifstream ifs(argv[1]);
    std::string word;
    isInRange is1to10(1, 10), is1to9(1, 9), is10plus(10, 0xffffffffffffffff);
    unsigned int count[] = {0, 0, 0};
    while (ifs >> word) {
        if (is1to10(word)) {
            ++count[0];
        }
        if (is1to9(word)) {
            ++count[1];
        }
        if (is10plus(word)) {
            ++count[2];
        }
    }
    std::cout << "[1, 10] : " << count[0] << std::endl;
    std::cout << "[1, 9] : " << count[1] << std::endl;
    std::cout << "[10, max) : " << count[2] << std::endl;
}
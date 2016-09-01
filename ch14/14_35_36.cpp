#include <iostream>
#include <vector>

class ReadString {
public:
    ReadString(std::istream &i = std::cin) : is(i) {}
    std::string operator()() {
        std::string last;
        getline(is, last);
        return is? last : std::string();
    }
private:
    std::istream& is;
};

int main() {
    ReadString rs;
    std::vector<std::string> vec;
    std::string line = rs();
    while (line.size() > 0) {
        vec.push_back(line);
        line = rs();
    }
    for (const std::string &s : vec) {
        std::cout << s << std::endl;
    }
    return 0;
}
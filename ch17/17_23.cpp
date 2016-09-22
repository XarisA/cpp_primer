#include <regex>
#include <iostream>

int main() {
    std::string zipcode = "(\\d{5})([-])?(\\d{4})?";
    std::regex r(zipcode);
    std::string s;
    while(getline(std::cin, s)) {
        for (std::sregex_iterator it(s.begin(), s.end(), r), end_it;
                it != end_it; ++it) {
            std::cout << it->str() << std::endl;
        }
    }

    return 0;
}
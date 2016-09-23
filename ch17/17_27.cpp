#include <regex>
#include <iostream>

int main() {
    std::string zipcode = "(\\d{5})([-])?(\\d{4})";
    std::string fmt = "$1-$3";
    std::regex r(zipcode);
    std::string s;
    std::smatch m;
    while (std::cin >> s) {
        if (std::regex_match(s, r))
            std::cout << std::regex_replace(s, r, fmt) << std::endl;
        else
            std::cout << "Invalid input!" << std::endl;
    }

    return 0;
}
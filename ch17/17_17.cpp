#include <iostream>
#include <regex>

int main() {
    std::regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::string s;
    getline(std::cin, s);
    std::cout << "Violation:" << std::endl;
    for (std::sregex_iterator it(s.cbegin(), s.cend(), r), it_end; 
                                            it !=it_end; ++it) {
        // TODO: for ex 17.18, we need a dictionary of words
        std::cout << it->str() << std::endl;
    }
    return 0;
}
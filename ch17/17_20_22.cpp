#include <regex>
#include <iostream>

bool valid(const std::smatch &m) {
    if (m[1].matched)
        return m[3].matched && (!m[4].matched || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

int main() {
    std::string phone_num =
        "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
        // TODO: ex 17.22, match any number of whitespace
    std::regex r(phone_num);
    std::string s;
    while(getline(std::cin, s)) {
        for (std::sregex_iterator it(s.begin(), s.end(), r), end_it;
                it != end_it; ++it) {
            if(valid(*it))
                std::cout << "Valid: ";
            else
                std::cout << "Not valid: ";
            std::cout << it->str() << std::endl;
        }
    }

    return 0;
}
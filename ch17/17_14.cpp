#include <regex>
#include <iostream>

int main() {
    try {
        std::regex r1("[[:alnum:]");
    } catch (std::regex_error e) {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }

    try {
        std::regex r2("(a|b");
    } catch (std::regex_error e) {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }

    try {
        std::regex r3("~!@#$%^&*-->;)}");
    } catch (std::regex_error e) {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }

    return 0;
}
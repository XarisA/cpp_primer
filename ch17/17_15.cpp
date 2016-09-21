#include <iostream>
#include <regex>

int main() {
    std::regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::string user_input;
    std::cout << "Please input a word or input q to quit." << std::endl;
    while (std::cin >> user_input && user_input != "q") {
        if (std::regex_match(user_input, r))
            std::cout << "The word " << user_input << " violates the rule!\n";
        else
            std::cout << "The word " << user_input << " is OK!\n";
        std::cout << "Please input a word or input q to quit." << std::endl;
    }
    return 0;
}
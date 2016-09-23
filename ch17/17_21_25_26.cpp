#include <regex>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using std::istringstream;
using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

bool valid(const std::smatch &m) {
    if (m[1].matched)
        return m[3].matched && (!m[4].matched || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char** argv) {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream in(argv[1]);

    while (getline(in, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        /*
        ex 17.25:

        record >> word;
        info.phones.push_back(word);
        */

        /*
        ex 17.26

        record >> word;     // the first number
        while (record >> word) {
            info.phones.push_back(word);
        }
        */

        people.push_back(info);
    }
    
    std::string phone_num =
        "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    std::regex r(phone_num);

    for (const auto &entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            std::smatch results;
            std::regex_search(nums, results, r);
            if (results.size() == 0 || !valid(results)) {
                badNums << " " << nums;
            }
            else
                formatted << " " << nums;
        }
        if (badNums.str().empty())
            std::cout << entry.name << " "
                        << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name
                        << " invalid number(s) " << badNums.str() << std::endl;
    }

    return 0;
}
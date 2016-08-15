#include "12_19.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size()); 
}

int main(int argc, char **argv) {
    std::ifstream input(argv[1]);
    std::string text, word;
    while(getline(input, text)) {
        StrBlob sb;
        std::istringstream str_in(text);
        while (str_in >> word) {
            sb.push_back(word);
        }
        StrBlobPtr sbp(sb.begin());
        for (auto pbeg(sb.begin()), pend(sb.end()); pbeg != pend; pbeg.incr()){
            std::cout << pbeg.deref() << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
#include "QueryResult.hpp"

auto QueryResult::begin() {
    return lines->begin();
}

auto QueryResult::end() {
    return lines->end();
}

auto QueryResult::get_file() {
    return text;
}

std::string make_plural(size_t ctr, const std::string &word, 
                        const std::string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const QueryResult &q) {
    os << q.word << " occurs " << q.lines->size() << " " 
        << make_plural(q.lines->size(), "time") << std::endl;
    for (auto num : *q.lines) {
        os << "\t(line " << num + 1 << ") "
            << *(q.text->begin() + num) << std::endl;
    }
    return os;
}
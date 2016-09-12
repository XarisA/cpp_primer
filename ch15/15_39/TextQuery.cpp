#include "TextQuery.hpp"

TextQuery::TextQuery(std::ifstream &infile) :
                text(new std::vector<std::string>) {
    std::string line, word;
    while (getline(infile, line)) {
        text->push_back(line);
        int n = text->size() - 1;
        std::istringstream iss(line);
        while (iss >> word) {
            auto &lines = lines_record[word];
            if (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string& word) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = lines_record.find(word);
    if (loc == lines_record.end()) {
        return QueryResult(word, nodata, text);
    } 
    else {
        return QueryResult(word, loc->second, text);
    }
}

std::set<TextQuery::line_no>::iterator QueryResult::begin() {
    return lines->begin();
}

std::set<TextQuery::line_no>::iterator QueryResult::end() {
    return lines->end();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file() {
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
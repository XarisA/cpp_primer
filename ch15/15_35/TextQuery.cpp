#include "TextQuery.hpp"

TextQuery::TextQuery(std::ifstream &infile) : text(new std::vector<std::string>) {
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
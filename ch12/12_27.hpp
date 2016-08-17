#ifndef TEXT_QUERY
#define TEXT_QUERY

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using line_no = std::vector<std::string>::size_type;

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream &infile) : text(new std::vector<std::string>) {
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

    QueryResult query(const std::string&);
private:
    std::shared_ptr<std::vector<std::string>> text;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> lines_record;
};

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> w, std::shared_ptr<std::vector<std::string>> t)
                : word(s), lines(w), text(t) {}
private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> text;
};

QueryResult TextQuery::query(const std::string& word) {
    auto result = QueryResult(word, lines_record[word], text);
    return result;
}

#endif
#ifndef TEXT_QUERY
#define TEXT_QUERY

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

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

    QueryResult query(const std::string&) const;    // TODO
private:
    std::shared_ptr<std::vector<std::string>> text;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> lines_record;
};

#endif
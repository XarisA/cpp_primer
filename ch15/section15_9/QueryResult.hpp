#ifndef QUERYRESULT
#define QUERYRESULT

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using line_no = std::vector<std::string>::size_type;

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

#endif
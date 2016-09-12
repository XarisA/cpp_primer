#ifndef QUERY_RESULT
#define QUERY_RESULT

#include <vector>
#include <string>
#include <set>

using line_no = std::vector<std::string>::size_type;

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> w, 
                std::shared_ptr<std::vector<std::string>> t)
                : word(s), lines(w), text(t) { }
    auto begin();
    auto end();
    auto get_file();
private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> text;
};

std::string make_plural(size_t, const std::string&, const std::string&);

std::ostream &print(std::ostream&, const QueryResult&);

#endif
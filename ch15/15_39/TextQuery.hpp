#ifndef TEXT_QUERY
#define TEXT_QUERY

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>

class QueryResult;

class TextQuery {
public:
    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> text;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> lines_record;
};

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> w, 
                std::shared_ptr<std::vector<std::string>> t)
                : word(s), lines(w), text(t) { }
    std::set<TextQuery::line_no>::iterator begin();
    std::set<TextQuery::line_no>::iterator end();
    std::shared_ptr<std::vector<std::string>> get_file();
private:
    std::string word;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> text;
};

std::string make_plural(size_t, const std::string&, const std::string&);

std::ostream &print(std::ostream&, const QueryResult&);

#endif
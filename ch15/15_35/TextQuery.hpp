#ifndef TEXT_QUERY
#define TEXT_QUERY

#include "QueryResult.hpp"
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
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> text;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> lines_record;
};

#endif
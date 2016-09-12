#include "AndQuery.hpp"
#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(const TextQuery &text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(right.begin(), right.end(),
                         left.begin(), left.end(),
                         inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}
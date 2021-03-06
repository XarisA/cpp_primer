#include "Query.hpp"

namespace chapter15 {

    QueryResult NotQuery::eval(const chapter10::TextQuery &text) const {
        auto result = query.eval(text);
        auto ret_lines = std::make_shared<std::set<line_no>>();
        auto beg = result.begin(), end = result.end();
        auto sz = result.get_file()->size();
        for (size_t n = 0; n != sz; ++n) {
            if (beg == end || *beg != n) {
                ret_lines->insert(n);
            }
            else if (beg != end) {
                ++beg;
            }
        }
        return QueryResult(rep(), ret_lines, result.get_file());
    }

    QueryResult AndQuery::eval(const chapter10::TextQuery &text) const {
        auto right = rhs.eval(text), left = lhs.eval(text);
        auto ret_lines = std::make_shared<std::set<line_no>>();
        std::set_intersection(right.begin(), right.end(),
                            left.begin(), left.end(),
                            inserter(*ret_lines, ret_lines->begin()));
        return QueryResult(rep(), ret_lines, left.get_file());
    }

    QueryResult OrQuery::eval(const chapter10::TextQuery &text) const {
        auto right = rhs.eval(text), left = lhs.eval(text);
        auto ret_lines =
            std::make_shared<std::set<line_no>>(left.begin(), left.end());
        ret_lines->insert(right.begin(), right.end());
        return QueryResult(rep(), ret_lines, left.get_file());
    }
}
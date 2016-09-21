#include "../ch14/14_6_9.hpp"   // Sales_data header
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>

bool compareIsbn(const Sales_data &d1, const Sales_data &d2) {
    return d1.isbn() < d2.isbn();
}

// ex 17.4
typedef std::tuple<std::vector<Sales_data>::size_type,
                    std::vector<Sales_data>::const_iterator,
                    std::vector<Sales_data>::const_iterator> matches;

std::vector<matches> 
findBook_t(const std::vector<std::vector<Sales_data>> &files,
                                const std::string &book) {
    std::vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found = std::equal_range(it->cbegin(), it->cend(), 
                                        book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(std::make_tuple(it - files.cbegin(), 
                                            found.first, found.second));
    }
    return ret;
}

// ex 17.5
typedef std::pair<std::vector<Sales_data>::size_type,
                    std::pair<std::vector<Sales_data>::const_iterator,
                    std::vector<Sales_data>::const_iterator>> match_pairs;

std::vector<match_pairs> 
findBook_p(const std::vector<std::vector<Sales_data>> &files,
                                const std::string &book) {
    std::vector<match_pairs> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found = std::equal_range(it->cbegin(), it->cend(), 
                                        book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(std::make_pair(it - files.cbegin(), 
                        std::make_pair(found.first, found.second)));
    }
    return ret;
}

// ex 17.6
struct result {
    std::vector<Sales_data>::size_type index;
    std::vector<Sales_data>::const_iterator itbegin;
    std::vector<Sales_data>::const_iterator itend;
};

std::vector<result> 
findBook_c(const std::vector<std::vector<Sales_data>> &files,
                                const std::string &book) {
    std::vector<result> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found = std::equal_range(it->cbegin(), it->cend(), 
                                        book, compareIsbn);
        if (found.first != found.second) {
            result res;
            res.index = it - files.cbegin();
            res.itbegin = found.first;
            res.itend = found.second;
            ret.push_back(res);
        }
    }
    return ret;
}

int main() {
    // TODO
    return 0;
}
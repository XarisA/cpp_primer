#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

int main() {
    list<const char*> lst{"string1", "string2", "string3"};
    vector<string> vec;
    vec.assign(lst.cbegin(), lst.cend());
    for (auto &s : vec) {
        printf("%s\n", s.c_str());
    }
    return 0;
}
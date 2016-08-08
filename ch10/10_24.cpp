#include <vector>
#include <iostream>
#include <functional>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::find_if;
using std::bind;
using namespace std::placeholders;

bool check_size(const int i, string::size_type sz) {
    return i > sz;
}

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    string word("hello");
    auto it = find_if(numbers.begin(), numbers.end(), bind(check_size, _1, word.size()));
    if (it != numbers.end()) {
        cout << *it << endl;
    }

    return 0;
}
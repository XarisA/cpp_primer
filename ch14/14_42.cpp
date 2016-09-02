#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
    using std::placeholders::_1;
    std::vector<int> vi{1, 2, 3, 222, 2333, 1024, 10000};
    std::vector<std::string> vs{"pooh", "hello", "world", "pooh"};
    auto a = std::count_if(vi.cbegin(), vi.cend(), std::bind(std::greater<int>(), _1, 1024));
    std::cout << a << std::endl;
    
    auto b = std::find_if(vs.cbegin(), vs.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
    if (b != vs.cend()) {
        std::cout << *b << std::endl;
    }

    std::transform(vi.begin(), vi.end(), vi.begin(), std::bind(std::multiplies<int>(), _1, 2));
    for (const int i :vi) {
        std::cout << i << ' ';
    }

    return 0;
}
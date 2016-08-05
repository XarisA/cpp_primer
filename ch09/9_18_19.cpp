#include <deque>
#include <list>
#include <iostream>

using std::deque;
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    deque<string> dq;
    list<string> lst;
    string buff;
    while (cin >> buff) {
        dq.push_back(buff);
        lst.push_back(buff);
    }
    auto iter = dq.cbegin();
    while (iter != dq.cend()) {
        cout << *iter++ << endl;
    }
    cout << endl;
    auto iter2 = lst.cbegin();
    while (iter2 != lst.cend()) {
        cout << *iter2++ << endl;
    }
    return 0;
}
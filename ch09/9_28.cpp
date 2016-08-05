#include <forward_list>
#include <iostream>

using std::forward_list;
using std::cout;
using std::endl;
using std::string;

bool insert_string(forward_list<string> &l, const string &p, const string &i) {
    auto prev = l.before_begin();
    auto curr = l.begin();
    while (curr != l.end()) {
        if (*curr == p) {
            l.insert_after(curr, i);
            return true;
        } 
        else {
            prev = curr;
            ++curr;
        }
    }
    l.insert_after(prev, i);
    return false;
}

void print(forward_list<string> &l) {
    for (auto &s : l) {
        cout << s << ' ';
    }
    cout << endl;
}

int main() {
    forward_list<string> fl1{"1", "2", "3", "4"};
    insert_string(fl1, "1", "!");
    print(fl1);
    
    forward_list<string> fl2{"1", "2", "3", "4"};
    insert_string(fl2, "5", "!");
    print(fl2);
    
    return 0;
}
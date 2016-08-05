#include <stack>
#include <iostream>

using std::stack;
using std::string;
using std::cout;
using std::endl;

int main() {
    stack<char> charStack;
    string expression("this is a (test).");
    bool seen = false;

    for (auto c : expression) {
        if (c == '(') {
            seen = true;
            continue;
        }
        else if (c == ')') seen = false;
        if (seen)   charStack.push(c);
    }

    string str;
    while (!charStack.empty()) {
        str += charStack.top();
        charStack.pop();
    }

    cout << str << endl;

    return 0;

}
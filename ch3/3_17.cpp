#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> words;
    string word;
    while (cin >> word) {
        words.push_back(word);
    }
    int word_count = 0;
    for (auto &w : words) {
        transform(w.begin(), w.end(), w.begin(), ::toupper);
        if (word_count < 8) {
            cout << w << " ";
            word_count += 1;
        }
        else {
            cout << endl;
            word_count = 0;
        }
    }

    return 0;
}

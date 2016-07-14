#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
             spaceCnt = 0, tabCnt = 0, lineCnt = 0,
             ffCnt = 0, flCnt = 0, fiCnt = 0;
    char last;
    string ch;
    while (getline(cin, ch)) {
        ++lineCnt;
        for (auto c : ch) {
            switch (c) {
                case 'A': case 'a':
                    ++aCnt;
                    break;
                case 'E': case 'e':
                    ++eCnt;
                    break;
                case 'I': case 'i':
                    ++iCnt;
                    if (last == 'f') {
                        ++fiCnt;
                    }
                    break;
                case 'O': case 'o':
                    ++oCnt;
                    break;
                case 'U': case 'u':
                    ++uCnt;
                    break;
                case ' ':
                    ++spaceCnt;
                    break;
                case '\t':
                    ++tabCnt;
                    break;
                default:
                    if (last == 'f') {
                        if (c == 'f') {
                            ++ffCnt;
                        }
                        else if (c == 'l') {
                            ++flCnt;
                        }
                    }
            }
            last = c;
        }
        
    }
    cout << "a: " << aCnt << endl;
    cout << "e: " << eCnt << endl;
    cout << "i: " << iCnt << endl;
    cout << "o: " << oCnt << endl;
    cout << "u: " << uCnt << endl;
    cout << "tab: " << tabCnt << endl;
    cout << "line: " << lineCnt << endl;
    cout << "space: " << spaceCnt << endl;
    cout << "ff: " << ffCnt << endl;
    cout << "fl: " << flCnt << endl;
    cout << "fi: " << fiCnt << endl;
    return 0;
}
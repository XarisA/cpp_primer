#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    int grade;
    cin >> grade;
    char letterGrade = grade >= 90 ? 'A' :
                       grade >= 80 ? 'B' :
                       grade >= 70 ? 'C' :
                       grade >= 60 ? 'D' : 'F';
    cout << letterGrade << endl;
    return 0;
}
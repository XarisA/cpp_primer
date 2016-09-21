#include "Quiz.hpp"
#include <iostream>

int main() {
    quiz answer, student;
    answer.set(1, 1);
    answer.set(3, true);
    answer.set(5, 3);

    student.set(1, 1);
    //student.set(3, true);
    //student.set(5, 3);

    std::cout << grade(answer, student) << std::endl;

    return 0;
}
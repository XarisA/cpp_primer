#ifndef QUIZ
#define QUIZ

#include <cstddef>

class quiz {
    friend bool grade(const quiz&, const quiz&);
public:
    quiz() = default;
    void set(size_t pos, bool pof = true);
private:
    unsigned int data;
};

void quiz::set(size_t pos, bool pof) {
    if (pof) {   // if pass
        data |= 1U << pos;
    }
    else {
        data &= ~(1U << pos);
    }
}

bool grade(const quiz &q1, const quiz &q2) {
    return q1.data == q2.data;
}

#endif
#include "../ch14/14_6_9.hpp"       // Sales_data header
#include <string>

class Token {
public:
    Token() : tok(INT), ival{0} { }
    Token(const Token &t) : tok(t.tok) { copyUnion(t); }
    Token(Token &&) noexcept;   //TODO
    Token& operator=(const Token&);     //TODO
    Token& operator=(Token&&) noexcept;
    ~Token() { 
        if (tok == STR) sval.~string(); 
        else if (tok == SDT) sdval.~Sales_data();
    }

    Token& operator=(const std::string&);
    Token& operator=(const Sales_data&);
    Token& operator=(char);
    Token& operator=(int);
    Token& operator=(double);

private:
    enum {INT, CHAR, DBL, STR, SDT} tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
        Sales_data sdval;
    };
    void copyUnion(const Token&);
    void moveUnion(Token&&);
};

Token& Token::operator=(int i) {
    if (tok == STR) sval.~string();
    else if (tok == SDT) sdval.~Sales_data();
    ival = i;
    tok = INT;
    return *this;
}

Token& Token::operator=(double d) {
    if (tok == STR) sval.~string();
    else if (tok == SDT) sdval.~Sales_data();
    dval = d;
    tok = DBL;
    return *this;
}

Token& Token::operator=(char c) {
    if (tok == STR) sval.~string();
    else if (tok == SDT) sdval.~Sales_data();
    cval = c;
    tok = CHAR;
    return *this;
}

Token& Token::operator=(const std::string &s) {
    if (tok == STR) { sval = s; }
    else {
        if (tok == SDT) sdval.~Sales_data();
        new(&sval) std::string(s);
        tok = STR;
    }
    return *this;
}

Token& Token::operator=(const Sales_data &s) {
    if (tok == SDT) { sdval = s; }
    else {
        if (tok == STR) sval.~string();
        new(&sdval) Sales_data(s);
        tok = SDT;
    }
    return *this;
}

void Token::copyUnion(const Token &t) {
    switch (t.tok) {
        case Token::INT: ival = t.ival; break;
        case Token::DBL: dval = t.dval; break;
        case Token::CHAR: cval = t.cval; break;
        case Token::STR: new(&sval) std::string(t.sval); break;
        case Token::SDT: new(&sdval) Sales_data(t.sdval); break;
    }
}

Token& Token::operator=(const Token &t) {
    if (tok == STR && t.tok != STR) sval.~string();
    if (tok == SDT && t.tok != SDT) sdval.~Sales_data();
    if (tok == STR && t.tok == STR)
        sval = t.sval;
    else if (tok == SDT && t.tok == SDT)
        sdval = t.sdval;
    else
        copyUnion(t);
    tok = t.tok;
    return *this;
}

int main() {

    return 0;
}
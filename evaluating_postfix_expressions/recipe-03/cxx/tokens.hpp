#pragma once

#include <string>

class Token {
public:
    enum {
        UNKNOWN  = 0,       // unknown

        INT      = 4,       // integer
                
        MINUS    = 5,       // minus    operator
        PLUS     = 6,       // plus     operator
        MUL      = 7,       // multiply operator
        DIV      = 8,       // divide   operator
        EXPO     = 9,       // exponent operator
        LPAR     = 10,      // left par operator
        RPAR     = 11,      // rightpar operator

        FIRST_OP = 5,       // first operator code
    };

    Token() {
    }

    explicit Token(int val) {
        type = Token::INT;
        value.i = val;
    }

    explicit Token(char ch) {
        type = makeType(ch);
        value.c = ch;
    }

    bool isOperator() const {
        return type >= Token::FIRST_OP;
    }

    bool isOperand() const {
        return type == Token::INT;
    }

    std::string toString() const {
        if (isOperand()) {
            return std::to_string(value.i);
        } else {
            return std::string(1, value.c);
        }
    }

    int getType() const {
        return type;
    }

    int getValue() const {
        return value.i;
    }

    char getOperator() const {
        return value.c;
    }

    int makeType(char ch) {
        switch (ch) {
            case '*':
                return Token::MUL;
            case '/':
                return Token::DIV;
            case '+':
                return Token::PLUS;
            case '-':
                return Token::MINUS;
            case '(':
                return Token::LPAR;
            case ')':
                return Token::RPAR;
            default:
                return Token::UNKNOWN;
        }
    }

    int getPrecedence() {
        // Returns the precedunce level of an operator.
        switch (type) {
            case Token::MUL:
            case Token::DIV:
                return 2;
            case Token::PLUS:
            case Token::MINUS:
                return 1;
            default:
                return 0;
        }
    }

private:
    int type{};
    union value_union {
        int i;
        char c;
    } value{};
};

namespace std {

inline std::string to_string(const ::Token& t) {
    return t.toString();
}

}   // namespace std

inline bool operator== (const Token& lhs, const Token& rhs) {
    return lhs.getType() == lhs.getType() && lhs.getValue() == rhs.getValue();
}

inline bool operator!= (const Token& lhs, const Token& rhs) {
    return !(lhs == rhs);
}

inline bool operator< (const Token& lhs, const Token& rhs) {
    if (lhs.getType() < rhs.getType()) {
        return true;
    } else if (lhs.getType() == rhs.getType()) {
        return lhs.getValue() < rhs.getValue();
    } else {
        return false;
    }
}

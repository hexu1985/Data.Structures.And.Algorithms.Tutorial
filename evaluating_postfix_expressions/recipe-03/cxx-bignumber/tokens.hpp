#pragma once

#include <string>
#include <variant>
#include "bignumber.h"

class Token {
public:
    enum {
        UNKNOWN  = 0,       // unknown

        INT      = 4,       // integer
                
        MINUS    = 5,       // minus    operator
        PLUS     = 6,       // plus     operator
        MUL      = 7,       // multiply operator
        DIV      = 8,       // divide   operator
        LPAR     = 10,      // left par operator
        RPAR     = 11,      // rightpar operator

        FIRST_OP = 5,       // first operator code
    };

    Token() {
    }

    explicit Token(const BigNumber& i) {
        _type = Token::INT;
        value = i;
    }

    explicit Token(const std::string& s) {
        _type = makeType(s);
        value = s;
    }

    bool isOperator() const {
        return _type >= Token::FIRST_OP;
    }

    bool isOperand() const {
        return _type == Token::INT;
    }

    std::string toString() const {
        struct {
            std::string str;
            void operator()(const BigNumber& i) { str = i.getString(); }
            void operator()(const std::string& s) { str = s; }
        } visitor;

        std::visit(visitor, value);
        return visitor.str;
    }

    int getType() const {
        return _type;
    }

    const std::variant<std::string, BigNumber>& getValue() const {
        return value;
    }

    int getPrecedence() {
        // Returns the precedunce level of an operator.
        switch (_type) {
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
    int makeType(const std::string& ch) {
        if (ch == "*") {
            return Token::MUL;
        } else if (ch == "/") {
            return Token::DIV;
        } else if (ch == "+") {
            return Token::PLUS;
        } else if (ch == "-") {
            return Token::MINUS;
        } else if (ch == "(") {
            return Token::LPAR;
        } else if (ch == ")") {
            return Token::RPAR;
        } else {
            return Token::UNKNOWN;
        }
    }

private:
    int _type{};
    std::variant<std::string, BigNumber> value{};
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

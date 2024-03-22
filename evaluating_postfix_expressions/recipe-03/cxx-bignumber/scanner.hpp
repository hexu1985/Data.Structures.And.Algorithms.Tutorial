#pragma once

#include "tokens.hpp"
#include <string>
#include <stdexcept>

class Scanner {
public:
    static const char EOE = ';';        // end-of-expression

    Scanner(const std::string& sourceStr_): sourceStr(sourceStr_) {
        getFirstToken();
    }

    Scanner(Scanner&& other): sourceStr(std::move(other.sourceStr)),
        currentToken(other.currentToken),
        index(other.index),
        currentChar(other.currentChar)
    {
        other.currentToken = Token{};
    }

    bool hasNext() const {
        return currentToken != Token{};
    }

    Token next() {
        if (!hasNext()) {
            throw std::runtime_error("There are no more tokens");
        }
        auto temp = currentToken;
        getNextToken();
        return temp;
    }

    void getFirstToken() {
        index = 0;
        currentChar = sourceStr[0];
        getNextToken();
    }

    void getNextToken() {
        skipWhiteSpace();
        if (isdigit(currentChar)) {
            currentToken = Token{getInteger()};
        } else if (currentChar == EOE) {
            currentToken = Token{};
        } else {
            currentToken = Token{std::string(1, currentChar)};
            nextChar();
        }
    }

    void nextChar() {
        if (index >= sourceStr.length() - 1) {
            currentChar = Scanner::EOE;
        } else {
            index += 1;
            currentChar = sourceStr[index];
        }
    }

    void skipWhiteSpace() {
        while (isspace(currentChar)) {
            nextChar();
        }
    }

    BigNumber getInteger() {
        BigNumber num = 0;
        while (true) {
            num = num * 10 + (currentChar-'0');
            nextChar();
            if (!isdigit(currentChar)) {
                break;
            }
        }
        return num;
    }

private:
    std::string sourceStr{};
    Token currentToken{};
    int index{};
    char currentChar{};
};

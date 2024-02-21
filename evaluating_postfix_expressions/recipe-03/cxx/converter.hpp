#pragma once

#include "scanner.hpp"
#include <vector>
#include <stack>

class IFToPFConverter {
public:
    IFToPFConverter(Scanner&& scanner_): scanner(std::move(scanner_)) {
    }

    std::vector<Token> convert() {
        // Returns a list of tokens that represent the postfix
        // form.  Assumes that the infix expression is syntactically correct
        std::vector<Token> postfix;
        std::stack<Token> stack;
        while (scanner.hasNext()) {
            auto currentToken = scanner.next();
            if (currentToken.getType() == Token::INT) {
                postfix.push_back(currentToken);
            } else if (currentToken.getType() == Token::LPAR) {
                stack.push(currentToken);
            } else if (currentToken.getType() == Token::RPAR) {
                auto topOperator = stack.top(); stack.pop();
                while (topOperator.getType() != Token::LPAR) {
                    postfix.push_back(topOperator);
                    topOperator = stack.top(); stack.pop();
                }
            } else {
                while (!stack.empty() && 
                        stack.top().getPrecedence() >= currentToken.getPrecedence()) {
                    postfix.push_back(stack.top()); stack.pop();
                }
                stack.push(currentToken);
            }
        }
        while (!stack.empty()) {
            postfix.push_back(stack.top()); stack.pop();
        }
        return postfix;
    }

private:
    Scanner scanner;
};


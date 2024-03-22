#pragma once

#include "tokens.hpp"
#include "scanner.hpp"

#include <string>
#include <stack>
#include <stdexcept>
#include <memory>
#include <list>
#include <cmath>

namespace std {

inline std::string to_string(const std::stack<Token>& operandStack) {
    std::stack<Token> tempStack(operandStack);
    std::list<Token> operandList;
    while (!tempStack.empty()) {
        operandList.push_back(tempStack.top());
        tempStack.pop();
    }
    operandList.reverse();
    std::string result = "";
    for (const auto& token : operandList) {
        result += std::to_string(token);
        result += ' ';
    }
    return result;
}

}    // namespace std

class PFEvaluator {
public:
    PFEvaluator(Scanner&& scanner_): scanner(std::move(scanner_)) {
    }

    int evaluate() {
        while (scanner.hasNext()) {
            auto currentToken = scanner.next();
            expressionSoFar += std::to_string(currentToken) + " ";
            if (currentToken.getType() == Token::INT) {
                operandStack.push(currentToken);
            } else if (currentToken.isOperator()) {
                if (operandStack.size() < 2) {
                    throw std::logic_error("Too few operands on the stack");
                }
                auto t2 = operandStack.top(); operandStack.pop();
                auto t1 = operandStack.top(); operandStack.pop();
                auto result = Token(computeValue(currentToken, 
                                                 std::get<int>(t1.getValue()),
                                                 std::get<int>(t2.getValue())));
                operandStack.push(result);
            } else {
                throw std::logic_error("Unknown token type");
            }
        }
        if (operandStack.size() > 1) {
            throw std::logic_error("Too many operands on the stack");
        }
        auto result = operandStack.top(); operandStack.pop();
        return std::get<int>(result.getValue());
    }

    std::string toString() const {
        std::string result = "\n";
        if (expressionSoFar == "") {
            result += "Portion of expression processed: none\n";
        } else {
            result += "Portion of expression processed: " + \
                   expressionSoFar + "\n";
        }
        if (operandStack.empty()) {
            result += "The stack is empty";
        } else {
            result += "Operands on the stack          : " + \
                      std::to_string(operandStack);
        }
        return result;
    }

    int computeValue(const Token& op, int value1, int value2) {
        int result = 0;
        auto theType = op.getType();
        switch (theType) {
            case Token::PLUS:
                result = value1 + value2;
                break;
            case Token::MINUS:
                result = value1 - value2;
                break;
            case Token::MUL:
                result = value1 * value2;
                break;
            case Token::DIV:
                result = value1 / value2;
                break;
            default:
                throw std::runtime_error("Unknown operator");
        }
        return result;
    }

private:
    Scanner scanner;
    std::string expressionSoFar{};
    std::stack<Token> operandStack{};
};

namespace std {

inline std::string to_string(const PFEvaluator& evaluator) {
    return evaluator.toString();
}

}   // namespace std

class PFEvaluatorModel {
public:
    int evaluate(const std::string& sourceStr) {
        evaluator.reset(new PFEvaluator(Scanner(sourceStr)));
        auto value = evaluator->evaluate();
        return value;
    }

    std::string format(const std::string& sourceStr) {
        std::string normalizedStr = "";
        Scanner scanner(sourceStr);
        while (scanner.hasNext()) {
            normalizedStr += std::to_string(scanner.next()) + " ";
        }
        return normalizedStr;
    }

    std::string evaluationStatus() {
        return std::to_string(*evaluator);
    }

private:
    std::unique_ptr<PFEvaluator> evaluator{};
};

#!/usr/bin/env python3

from Token import Token
from Scanner import Scanner
from Stack import Stack

class IFToPFConverter:

    def __init__(self, scanner):
        self.expressionSoFar = ""
        self.operatorStack = Stack()
        self.scanner = scanner

    def convert(self):
        """Returns a list of tokens that represent the postfix
        form of sourceStr.  Assumes that the infix expression
        in sourceStr is syntactically correct"""
        postfix = list()
        while self.scanner.hasNext():
            currentToken = self.scanner.next()
            self.expressionSoFar += str(currentToken) + " "
            if currentToken.getType() == Token.UNKNOWN:
                raise AttributeError("Unrecognized symbol")
            if currentToken.getType() == Token.INT:
                postfix.append(currentToken)
            elif currentToken.getType() == Token.LPAR:
                self.operatorStack.push(currentToken)
            elif currentToken.getType() == Token.RPAR:
                if self.operatorStack.isEmpty():
                    raise AttributeError("Too few operators(No matching opening left parenthese found)")
                topOperator = self.operatorStack.pop()
                while topOperator.getType() != Token.LPAR:
                    postfix.append(topOperator)
                    if self.operatorStack.isEmpty():
                        raise AttributeError("Too few operators(No matching opening left parenthese found)")
                    topOperator = self.operatorStack.pop()
            else:
                while not self.operatorStack.isEmpty() and \
                      self.operatorStack.peek().getPrecedence() >= currentToken.getPrecedence():
                    postfix.append(self.operatorStack.pop())
                self.operatorStack.push(currentToken)
        while not self.operatorStack.isEmpty():
            if self.operatorStack.peek().getType() == Token.LPAR:
                raise AttributeError("Too few operators(No matching opening right parenthese found)")
            postfix.append(self.operatorStack.pop())
        return postfix
   
    def __str__(self):
        result = ""
        if self.expressionSoFar == "":
            result += "Portion of infix expression processed: none\n"
        else: 
            result += "Portion of infix expression processed: " + \
                   self.expressionSoFar + "\n"
        if self.operatorStack.isEmpty():
            result += "The stack is empty"
        else:
            result += "Operators on the stack          : " + \
                      str(self.operatorStack)
        return result

    def conversionStatus(self):
        return str(self)

    
def main():
    while True:
        sourceStr = input("Enter an infix expression: ")
        if sourceStr == "":
            break
        else:
            try:
                converter = IFToPFConverter(Scanner(sourceStr))
                postfix = converter.convert()
                print("Postfix:", end = " ")
                for token in postfix:
                    print(token, end = " ")
                print()
            except Exception as e:
                print(e)
                print(converter.conversionStatus())

if __name__ == "__main__":
    main()



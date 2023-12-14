"""
File: converter.py
Project 7.7

Add error recovery to the infix to postfix converter.

Defines a class that converts infix expressions to postfix form.
"""

from tokens import Token
from scanner import Scanner
from arraystack import ArrayStack

class IFToPFConverter(object):

    def __init__(self, scanner):
        self.expressionSoFar = ""
        self.operatorStack = ArrayStack()
        self.scanner = scanner


    def convert(self):
        """Returns a list of tokens that represent the postfix
        form of sourceStr.  Assumes that the infix expression
        in sourceStr is syntactically correct"""
        postfix = []
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
                    raise AttributeError("Too few operators")
                topOperator = self.operatorStack.pop()
                while topOperator.getType() != Token.LPAR:
                    postfix.append(topOperator)
                    if self.operatorStack.isEmpty():
                        raise AttributeError("Too few operators")
                    topOperator = self.operatorStack.pop()
            else:
                while not self.operatorStack.isEmpty() and \
                      currentToken.getType() != Token.EXPO and \
                      self.operatorStack.peek().getPrecedence() >= currentToken.getPrecedence():
                    postfix.append(self.operatorStack.pop())
                self.operatorStack.push(currentToken)
        while not self.operatorStack.isEmpty():
            postfix.append(self.operatorStack.pop())
        return postfix
   
    def __str__(self):
        result = "\n"
        if self.expressionSoFar == "":
            result += "Portion of expression processed: none\n"
        else: 
            result += "Portion of expression processed: " + \
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
                print(e, converter.conversionStatus())

if __name__ == "__main__":
    main()



"""
File: converter.py
Project 7.6

Add ^ operator that is right-associative, for exponentiation.

Defines a class that converts infix expressions to postfix form.
"""

from tokens import Token
from scanner import Scanner
from arraystack import ArrayStack

class IFToPFConverter(object):

    def __init__(self, scanner):
        self.scanner = scanner

    def convert(self):
        """Returns a list of tokens that represent the postfix
        form.  Assumes that the infix expression is syntactically correct"""
        postfix = []
        stack = ArrayStack()
        while self.scanner.hasNext():
            currentToken = self.scanner.next()
            if currentToken.getType() == Token.INT:
                postfix.append(currentToken)
            elif currentToken.getType() == Token.LPAR:
                stack.push(currentToken)
            elif currentToken.getType() == Token.RPAR:
                topOperator = stack.pop()
                while topOperator.getType() != Token.LPAR:
                    postfix.append(topOperator)
                    topOperator = stack.pop()
            else:
                while not stack.isEmpty() and \
                      currentToken.getType() != Token.EXPO and \
                      stack.peek().getPrecedence() >= currentToken.getPrecedence():
                    postfix.append(stack.pop())
                stack.push(currentToken)
        while not stack.isEmpty():
            postfix.append(stack.pop())
        return postfix
   

def main():
    while True:
        sourceStr = input("Enter an infix expression: ")
        if sourceStr == "": break
        else:
            converter = IFToPFConverter(Scanner(sourceStr))
            postfix = converter.convert()
            print("Postfix:", end = " ")
            for token in postfix:
                print(token, end = " ")
            print()

if __name__ == "__main__":
    main()



"""
File: tokens.py
Project 7.6

Adds ^ operator for exponentiation.
Tokens for processing expressions.
"""

class Token(object):

    UNKNOWN  = 0        # unknown
    
    INT      = 4        # integer
            
    MINUS    = 5        # minus    operator
    PLUS     = 6        # plus     operator
    MUL      = 7        # multiply operator
    DIV      = 8        # divide   operator
    EXPO     = 9        # exponent operator
    LPAR     = 10       # left par operator
    RPAR     = 11       # rightpar operator

    FIRST_OP = 5        # first operator code

    def __init__(self, value):
        if type(value) == int:
            self._type = Token.INT
        else:
            self._type = self._makeType(value)
        self._value = value

    def isOperator(self):
        return self._type >= Token.FIRST_OP

    def __str__(self):
        return str(self._value)
    
    def getType(self):
       return self._type
    
    def getValue(self):
       return self._value

    def _makeType(self, ch):
        if   ch == '*': return Token.MUL
        elif ch == '/': return Token.DIV
        elif ch == '+': return Token.PLUS
        elif ch == '-': return Token.MINUS
        elif ch == '^': return Token.EXPO
        elif ch == '(': return Token.LPAR
        elif ch == ')': return Token.RPAR
        else:           return Token.UNKNOWN

    def getPrecedence(self):
        """Returns the precedunce level of an operator."""
        myType = self._type
        if myType == Token.EXPO:
            return 3
        if myType in (Token.MUL, Token.DIV):
            return 2
        elif myType in (Token.PLUS, Token.MINUS):
            return 1
        else:
            return 0

def main():
    # A simple tester program
    plus = Token("+")
    minus = Token("-")
    mul = Token("*")
    div = Token("/")
    expo = Token("^")
    unknown = Token("#")
    anInt = Token(34)
    print(plus, minus, mul, div, expo, unknown, anInt)

if __name__ == '__main__': 
    main()


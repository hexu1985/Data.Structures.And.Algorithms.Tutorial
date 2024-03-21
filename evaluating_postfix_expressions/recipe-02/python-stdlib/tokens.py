"""
File: tokens.py
Project 7.4

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

    FIRST_OP = 5        # first operator code

    def __init__(self, value):
        if type(value) == int:
            self.type = Token.INT
        else:
            self.type = self.makeType(value)
        self.value = value

    def isOperator(self):
        return self.type >= Token.FIRST_OP

    def __str__(self):
        return str(self.value)
    
    def getType(self):
       return self.type
    
    def getValue(self):
       return self.value

    def makeType(self, ch):
        if   ch == '*': return Token.MUL
        elif ch == '/': return Token.DIV
        elif ch == '+': return Token.PLUS
        elif ch == '-': return Token.MINUS
        elif ch == '^': return Token.EXPO
        else:           return Token.UNKNOWN

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


"""
File: scanner.py
A scanner for processing languages.
"""

from tokens import Token

class Scanner(object):

    EOE = ';'        # end-of-expression
    TAB = '\t'       # tab

    def __init__(self, sourceStr):
        self.sourceStr = sourceStr
        self.getFirstToken()

    def hasNext(self):
        return self.currentToken != None

    def next(self):
        if not self.hasNext():
            raise Exception("There are no more tokens")           
        temp = self.currentToken
        self.getNextToken()
        return temp

    def getFirstToken(self):
        self.index = 0
        self.currentChar = self.sourceStr[0]
        self.getNextToken()
    
    def getNextToken(self):
        self.skipWhiteSpace()
        if self.currentChar.isdigit():
            self.currentToken = Token(self.getInteger())
        elif self.currentChar == Scanner.EOE:
            self.currentToken = None
        else:
            self.currentToken = Token(self.currentChar)
            self.nextChar()
    
    def nextChar(self):
        if self.index >= len(self.sourceStr) - 1:
            self.currentChar = Scanner.EOE
        else:
            self.index += 1
            self.currentChar = self.sourceStr[self.index]
    
    def skipWhiteSpace(self):
        while self.currentChar in (' ', Scanner.TAB):
            self.nextChar()
    
    def getInteger(self):
        num = 0
        while True:
            num = num * 10 + int(self.currentChar)
            self.nextChar()
            if not self.currentChar.isdigit():
                break
        return num


def main():
    # A simple tester program
    while True:
        sourceStr = input("Enter an expression: ")
        if sourceStr == "": break
        scanner = Scanner(sourceStr)
        while scanner.hasNext():
            print(scanner.next())

if __name__ == '__main__': 
    main()


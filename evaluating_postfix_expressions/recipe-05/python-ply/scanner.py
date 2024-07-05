import ply.lex as lex

from tokens import Token

class Scanner:
    # List of token names.   This is always required
    tokens = (
       'NUMBER',
       'PLUS',
       'MINUS',
       'TIMES',
       'DIVIDES',
       'EXPONENT',
       'LPAREN',
       'RPAREN',
    )

    # Regular expression rules for simple tokens
    t_PLUS     = r'\+'
    t_MINUS    = r'-'
    t_TIMES    = r'\*'
    t_DIVIDES  = r'/'
    t_EXPONENT = r'\^'
    t_LPAREN   = r'\('
    t_RPAREN   = r'\)'

    # A regular expression rule with some action code
    # Note addition of self parameter since we're in a class
    def t_NUMBER(self,t):
        r'\d+'
        t.value = int(t.value)    
        return t

    # Define a rule so we can track line numbers
    def t_newline(self,t):
        r'\n+'
        t.lexer.lineno += len(t.value)

    # A string containing ignored characters (spaces and tabs)
    t_ignore  = ' \t'

    # Error handling rule
    def t_error(self,t):
        print("Illegal character '%s'" % t.value[0])
        t.lexer.skip(1)

    def __init__(self, sourceStr):
        self.lexer = lex.lex(module=self)
        self.lexer.input(sourceStr)
        self.getNextToken()

    def hasNext(self):
        return self.currentToken != None

    def next(self):
        if not self.hasNext():
            raise Exception("There are no more tokens")           
        temp = self.currentToken
        self.getNextToken()
        return temp

    def getNextToken(self):
        tok = self.lexer.token()
        if tok is None:
            self.currentToken = None
        else:
            self.currentToken = Token(tok.value)


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


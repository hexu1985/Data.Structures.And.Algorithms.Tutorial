import ply.lex as lex

class Scanner:
    # List of token names.   This is always required
    tokens = (
       'INT',
       'PLUS',
       'MINUS',
       'MUL',
       'DIV',
    )

    # Regular expression rules for simple tokens
    t_PLUS    = r'\+'
    t_MINUS   = r'-'
    t_MUL     = r'\*'
    t_DIV     = r'/'

    # A regular expression rule with some action code
    # Note addition of self parameter since we're in a class
    def t_INT(self,t):
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
        self.getFirstToken()

    def 

    # Test it output
    def test(self):
        while True:
             tok = self.lexer.token()
             if not tok: break
             print(tok)

def main():
    # Build the lexer and try it out
    scanner = Scanner("3 + 4")
    scanner.test()

if __name__ == '__main__': 
    main()


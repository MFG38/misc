#############
# CONSTANTS #
#############

DIGITS = '0123456789'

##########
# TOKENS #
##########

T_INT = 'INT'
T_FLOAT = 'FLOAT'
T_PLUS = 'PLUS'
T_MINUS = 'MINUS'
T_MUL = 'MUL'
T_DIV = 'DIV'
T_PARENL = 'PARENL'
T_PARENR = 'PARENR'

class Token:
    def __init__(self, type_, value=None):
        self.type = type_
        self.value = value
    
    def __repr__(self):
        if self.value: return f'{self.type}:{self.value}'
        return f'{self.type}'

##########
# ERRORS #
##########

class Error:
    def __init__(self, posStart, posEnd, errorName, details):
        self.posStart = posStart
        self.posEnd = posEnd
        self.errorName = errorName
        self.details = details
    
    def as_string(self):
        result = f'{self.errorName}: {self.details}\n'
        result += f'File {self.posStart.fn}, line {self.posStart.ln + 1}'
        return result

class IllegalChar(Error):
    def __init__(self, posStart, posEnd, details):
        super().__init__(posStart, posEnd, 'Illegal Character', details)

############
# POSITION #
############

class Position:
    def __init__(self, index, ln, col, fn, ftxt):
        self.index = index
        self.ln = ln
        self.col = col
        self.fn = fn
        self.ftxt = ftxt
    
    def advance(self, curChar):
        self.index += 1
        self.col += 1
        
        if curChar == '\n':
            self.ln += 1
            self.col = 0
        return self
    
    def copy(self):
        return Position(self.index, self.ln, self.col, self.fn, self.ftxt)

#########
# LEXER #
#########

class Lexer:
    def __init__(self, fn, text):
        self.fn = fn
        self.text = text
        self.pos = Position(-1, 0, -1, fn, text)
        self.curChar = None
        self.advance()
    
    def advance(self):
        self.pos.advance(self.curChar)
        self.curChar = self.text[self.pos.index] if self.pos.index < len(self.text) else None
    
    def make_tokens(self):
        tokens = []
        
        while self.curChar != None:
            if self.curChar in ' \t':
                self.advance()
            elif self.curChar in DIGITS:
                tokens.append(self.make_number())
            elif self.curChar == '+':
                tokens.append(Token(T_PLUS))
                self.advance()
            elif self.curChar == '-':
                tokens.append(Token(T_MINUS))
                self.advance()
            elif self.curChar == '*':
                tokens.append(Token(T_MUL))
                self.advance()
            elif self.curChar == '/':
                tokens.append(Token(T_DIV))
                self.advance()
            elif self.curChar == '(':
                tokens.append(Token(T_PARENL))
                self.advance()
            elif self.curChar == ')':
                tokens.append(Token(T_PARENR))
                self.advance()
            else:
                posStart = self.pos.copy()
                ic = self.curChar
                self.advance()
                return [], IllegalChar(posStart, self.pos, ic)
        return tokens, None
    
    def make_number(self):
        numStr = ''
        dotCount = 0
        
        while self.curChar != None and self.curChar in DIGITS + '.':
            if self.curChar == '.':
                if dotCount == 1: break
                dotCount += 1
                numStr += '.'
            else:
                numStr += self.curChar
            self.advance()
        
        if dotCount == 0:
            return Token(T_INT, int(numStr))
        else:
            return Token(T_FLOAT, float(numStr))

##########
# RUNNER #
##########

def run(fn, text):
    lex = Lexer(fn, text)
    tokens, error = lex.make_tokens()
    
    return tokens, error

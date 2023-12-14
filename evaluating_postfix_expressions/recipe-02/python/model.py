"""
File: model.py
Project 7.3
Defines PFEvaluatorModel and PFEvaluator
"""

from tokens import Token
from scanner import Scanner
from arraystack import ArrayStack

class PFEvaluatorModel(object):

    def evaluate(self, sourceStr):
        self.evaluator = PFEvaluator(Scanner(sourceStr))
        value = self.evaluator.evaluate()
        return value
   
    def format(self, sourceStr):
        normalizedStr = ""
        scanner = Scanner(sourceStr);
        while scanner.hasNext():
            normalizedStr += str(scanner.next()) + " "
        return normalizedStr;   

    def evaluationStatus(self):
        return str(self.evaluator)

    
class PFEvaluator(object):
   
    def __init__(self, scanner):
        self.expressionSoFar = ""
        self.operandStack = ArrayStack()
        self.scanner = scanner

    def evaluate(self):
        while self.scanner.hasNext():
            currentToken = self.scanner.next()
            self.expressionSoFar += str(currentToken) + " "
            if currentToken.getType() == Token.INT:
                self.operandStack.push(currentToken)
            elif currentToken.isOperator(): 
                if len(self.operandStack) < 2:
                    raise AttributeError("Too few operands on the stack")
                t2 = self.operandStack.pop()
                t1 = self.operandStack.pop()
                result = Token(self.computeValue(currentToken,
                                                 t1.getValue(),
                                                 t2.getValue()))
                self.operandStack.push(result)

            else:
                raise AttributeError("Unknown token type")
        if len(self.operandStack) > 1:
            raise AttributeError("Too many operands on the stack")
        result = self.operandStack.pop()
        return result.getValue();   

    def __str__(self):
        result = "\n"
        if self.expressionSoFar == "":
            result += "Portion of expression processed: none\n"
        else: 
            result += "Portion of expression processed: " + \
                   self.expressionSoFar + "\n"
        if self.operandStack.isEmpty():
            result += "The stack is empty"
        else:
            result += "Operands on the stack          : " + \
                      str(self.operandStack)
        return result

    def computeValue(self, op, value1, value2):
        result = 0;
        theType = op.getType()
        if theType == Token.PLUS:
            result = value1 + value2;
        elif theType == Token.MINUS:
            result = value1 - value2;
        elif theType == Token.MUL:
            result = value1 * value2;
        elif theType == Token.DIV:
            result = value1 // value2;
        elif theType == Token.EXPO:
            result = value1 ** value2;
        else:
            raise Exception("Unknown operator")
        return result

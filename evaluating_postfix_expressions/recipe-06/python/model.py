"""
File: model.py
Project 7.8

Integrate the infix to postfix converter into the evaluator.
"""

from tokens import Token
from scanner import Scanner
from arraystack import ArrayStack
from converter import IFToPFConverter

class PFEvaluatorModel(object):

    def evaluate(self, sourceStr):
        self.evaluator = None
        self.converter = IFToPFConverter(Scanner(sourceStr))
        postfix = self.converter.convert()
        self.evaluator = PFEvaluator(postfix)
        value = self.evaluator.evaluate()
        return value
   
    def format(self, sourceStr):
        normalizedStr = ""
        scanner = Scanner(sourceStr);
        while scanner.hasNext():
            normalizedStr += str(scanner.next()) + " "
        return normalizedStr;   

    def evaluationStatus(self):
        """Check to see if an evaluation has been done first."""
        if self.evaluator is None:
            evalStatus = ""
        else:
            evalStatus = str(self.evaluator)
        return str(self.converter) + "\n" + evalStatus

    
class PFEvaluator(object):
   
    def __init__(self, postfix):
        self.expressionSoFar = ""
        self.operandStack = ArrayStack()
        self.postfix = postfix
        
    def evaluate(self):
        for currentToken in self.postfix:
            self.expressionSoFar += str(currentToken) + " "
            if currentToken.getType() == Token.INT:
                self.operandStack.push(currentToken)
            else: 
                t2 = self.operandStack.pop()
                t1 = self.operandStack.pop()
                result = Token(self.computeValue(currentToken,
                                                t1.getValue(),
                                                t2.getValue()))
                self.operandStack.push(result)
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
            if value2 == 0:
                raise ZeroDivisionError("Attempt to divide by 0")
            result = value1 // value2;
        elif theType == Token.EXPO:
            result = value1 ** value2;
        else:
            raise AttibuteError("Unknown operator")
        return result

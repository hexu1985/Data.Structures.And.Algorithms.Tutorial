#!/usr/bin/env python3

from io import StringIO
from Scanner import Scanner
from PFEvaluator import PFEvaluator
from IFToPFConverter import IFToPFConverter

class IFEvaluatorModel:
   
    def evaluate(self, sourceStr):
        self.evaluator = None
        self.converter = IFToPFConverter(Scanner(sourceStr))
        postfixStr = self.postfixStr(self.converter.convert())
        self.evaluator = PFEvaluator(Scanner(postfixStr))
        value = self.evaluator.evaluate()
        return value

    def postfixStr(self, postfix):
        strBuffer = StringIO()
        for token in postfix:
            print(token, end = " ", file=strBuffer)
        return strBuffer.getvalue()

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

def test_evaluator(evaluator, sourceStr):
    try:
        print(evaluator.format(sourceStr))
        print(evaluator.evaluate(sourceStr))
    except Exception as e:
        print(e, evaluator.evaluationStatus())

def main():
    # A simple tester program
    evaluator = IFEvaluatorModel()
    test_evaluator(evaluator, "8 + 2 * 3")
    test_evaluator(evaluator, "(8 + 2) * 3")
    test_evaluator(evaluator, "(8 + 2 * 3")
    test_evaluator(evaluator, "8 + 2) * 3")

if __name__ == "__main__":
    main()

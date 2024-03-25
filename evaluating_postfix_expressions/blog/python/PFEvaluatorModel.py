#!/usr/bin/env python3

from Token import Token
from Scanner import Scanner
from Stack import Stack
from PFEvaluator import PFEvaluator

class PFEvaluatorModel:

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

def test_evaluator(evaluator, sourceStr):
    try:
        print(evaluator.format(sourceStr))
        print(evaluator.evaluate(sourceStr))
    except Exception as e:
        print(e, evaluator.evaluationStatus())

def main():
    # A simple tester program
    evaluator = PFEvaluatorModel()
    test_evaluator(evaluator, "4 5 6 * + 3 -")
    test_evaluator(evaluator, "1 9 * /")
    test_evaluator(evaluator, "2 3 5 +")

if __name__ == "__main__":
    main()

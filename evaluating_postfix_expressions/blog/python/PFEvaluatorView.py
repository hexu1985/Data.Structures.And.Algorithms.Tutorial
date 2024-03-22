#!/usr/bin/env python3

from PFEvaluatorModel import PFEvaluatorModel

class PFEvaluatorView:

    def run(self):
        evaluator = PFEvaluatorModel()
        while True:
            sourceStr = input("Enter a postfix expression: ")
            if sourceStr == "": break
            try:
                print(evaluator.format(sourceStr))
                print(evaluator.evaluate(sourceStr))
            except Exception as e:
                print(e, evaluator.evaluationStatus())

PFEvaluatorView().run()

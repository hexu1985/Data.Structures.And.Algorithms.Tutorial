#!/usr/bin/env python3

from IFEvaluatorModel import IFEvaluatorModel

class IFEvaluatorView:

    def run(self):
        evaluator = IFEvaluatorModel()
        while True:
            sourceStr = input("Enter an infix expression: ")
            if sourceStr == "": break
            try:
                print(evaluator.format(sourceStr))
                print(evaluator.evaluate(sourceStr))
            except Exception as e:
                print(e)
                print(evaluator.evaluationStatus())
            print()

IFEvaluatorView().run()


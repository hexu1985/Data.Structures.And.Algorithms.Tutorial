#include "model.hpp"
#include "input.hpp"
#include "print.hpp"

class PFEvaluatorView {
public:
    void run() {
        PFEvaluatorModel evaluator;
        while (true) {
            auto sourceStr = input("Enter an expression: ");
            if (sourceStr == "") break;
            try 
            {
                print(evaluator.format(sourceStr));
                print(evaluator.evaluate(sourceStr));
            } 
            catch (const std::exception& e)
            {
                print(e.what(), evaluator.evaluationStatus());
            }
        }
    }
};

int main() {
    PFEvaluatorView{}.run();
}

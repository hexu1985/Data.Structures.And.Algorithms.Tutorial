## 算术表达式计算程序：Python语言实现

本文介绍通过Python语言实现算术表达式计算程序的过程。

我们将按照软件工程的基本步骤来介绍：
- 需求
- 分析
- 设计
- 实现

### 程序的需求

我们的程序具有如下功能：
- 用户在提示符下输入一个算术表达式，然后程序会显示该表达式的值，
- 如果该表达式无效的话，则显示错误消息。

这是程序交互的一个示例：
```
Enter an infix expression: 12 + 3 * 2 - 10 / 2
12 + 3 * 2 - 10 / 2
13

Enter an infix expression: 12 - 4 * 5
12 - 4 * 5
-8

Enter an infix expression: (12 - 4) * 5
( 12 - 4 ) * 5
40

Enter an infix expression: (12 - 4 * 5
( 12 - 4 * 5
Too few operators(No matching opening right parenthese found)
Portion of infix expression processed: ( 12 - 4 * 5
Operators on the stack          : [(]

Enter an infix expression: 12 - 4) * 5
12 - 4 ) * 5
Too few operators(No matching opening left parenthese found)
Portion of infix expression processed: 12 - 4 )
The stack is empty

Enter an infix expression: 12 + * 3
12 + * 3
Too few operands on the stack
Portion of infix expression processed: 12 + * 3
The stack is empty
Portion of postfix expression processed: 12 3 * +
Operands on the stack          : [36]

Enter an infix expression: 23 + 34 34
23 + 34 34
Too many operands on the stack
Portion of infix expression processed: 23 + 34 34
The stack is empty
Portion of postfix expression processed: 23 34 34 +
Operands on the stack          : [23, 68]

Enter an infix expression: 12 % 2 + 4
12 % 2 + 4
Unrecognized symbol
Portion of infix expression processed: 12 %
The stack is empty

Enter an infix expression: 12 + 4 / 0
12 + 4 / 0
integer division or modulo by zero
Portion of infix expression processed: 12 + 4 / 0
The stack is empty
Portion of postfix expression processed: 12 4 0 /
Operands on the stack          : [12]

Enter an infix expression:
```

我们的程序中支持的算术表达式具有以下限制：
- 算术表达式采取中缀表示法（即日常的数学表达式）
- 运算数只支持正整数（负整数可以通过$0 - 正整数$获取）
- 运算符支持加、减、乘、除四则运算，优先级复合标准的四则运算
- 表达式支持括号`()`，支持嵌套的括号`()`

输入输出的格式具有以下限制：
- 输入表达式的时候，限定表达式在一行文本之内，
- 运算数和运算符之间可以有任意空白。
- 当用户按下了Enter键之后，按照在每个符号之间只有一个空格的项是显示表达式，
- 在后面新的一行开始，紧跟着的是表达式的值或者错误消息，
- 用户通过在提示符直接按下Enter键来退出。

程序中检测并报告一些输入错误：
- 不匹配的括号，
- 表达式包含太少的运算数，
- 表达式包含太多的运算数，
- 表达式包含了不识别的符号：程序期待表达式包含整数、4中运算符（+、-、*、/）以及空白（空格和制表符）。任何其他内容都是不识别的。
- 表达式包含了除以0的情况。

### 程序的分析

我们计算算术表达式的处理过程主要分为两大步骤
- 将中缀表达式转化成等价的后缀表达式，
- 计算后缀表达式的结果

所以我们的设计中，首先想到的实现中缀转后缀和计算后缀表达式的类：
- IFToPFConverter类：中缀表达式转后缀表达式的类
- PFEvaluator类：计算后缀表达式的类
- Stack类：栈类，中缀表达式转后缀表达式，以及后缀表达式的计算中都会用到

另外，将输入的一行表达式转换成符号序列的功能，也需要两个类：
- Token类：表示符号，包括运算数和运算符
- Scanner类：扫描一行字符串，转化成符号序列

顶层采用了视图和模型的模式：
- IFEvaluatorView类：视图类
    + 视图要求模型按照每个符号之间只有一个空格的格式来格式化表达式字符串，然后，显示格式化后的字符串。
    + 视图要求模型计算表达式，然后显示返回的值
    + 视图捕获模型所抛出的任何异常，要求模型给出当检测到错误的时候的参照条件，并且显示相应的错误信息。
- IFEvaluatorModel类：模型类
    + 它必须能够格式化并计算表达式字符串
    + 它可以引发异常以响应字符串中的语法错误，并且报告其内部状态。

具体的类关系图如下：

![表达式计算程序的类图](evaluate_class.png)


### 程序的设计

我们接下来给出每个类的具体接口和含义。

首先根据类关系图，给出对应的类之间接口交互图。

![表达式计算程序的交互图](evaluate_interaction.png)

接下来分别罗列各个类的接口和含义。

1. IFEvaluatorView类

    - 主要的方法就一个run()，具体的代码逻辑如下图：

    ![IFEvaluatorView.run()流程图](IFEvaluatorView_flow.png)

2. IFEvaluatorModel类
    模型包括format()、evaluate()和evaluationStatus()这三个方法，下面分别说明：

    - format(expressionStr)的流程如下图：

    ![IFEvaluatorModel.format()流程图](IFEvaluatorModel_format_flow.png)

    - evaluate(expressionStr)的流程很简单：
        + 创建一个IFToPFConverter类对象，将Scanner(expressionStr)传入IFToPFConverter，获取后缀表达式
        + 创建一个PFEvaluator类对象，将Scanner(后缀表达式字符串)传入PFEvaluator，返回计算结果

    - evaluationStatus()：
        + 获取IFToPFConverter的状态信息和PFEvaluator的状态信息并返回

3. IFToPFConverter类
    包括构造函数，以及convert()和conversionStatus()方法：

    - 构造函数IFToPFConverter(scanner)：
        + 创建operatorStack，用来存放运算符的栈
        + 保存传入的scanner

    - convert()：
        + 遍历scanner中的Token
        + 返回后缀表达式的Token列表

    - conversionStatus()返回多行字符串：
        + 已经被处理的表达式字符串部分
        + 当前operatorStack上的符号

4. PFEvaluator类
    包括构造函数，以及evaluate()和evaluationStatus()方法：

    - 构造函数PFEvaluator(scanner)：
        + 创建operandStack，用来存放运算数的栈
        + 保存传入的scanner

    - evaluate()：
        + 遍历scanner中的Token
        + 返回后缀表达式的计算结果

    - evaluationStatus()返回多行字符串：
        + 已经被处理的表达式字符串部分
        + 当前operandStack上的符号

5. Scanner类
    包括构造函数，以及hasNext()和next()方法：

    - 构造函数Scanner(sourceStr)：保存sourceStr字符串，用作后续扫描并提取符号（Token）
    - hasNext()：如果字符串序列中还有下一个符号（Token），返回True，否则返回False
    - next()：返回下一个符号（Token），如果hasNext()返回Flase了，则抛出异常。

6. Token类
    包含两个成员变量：type和value。
    - type标识符号的类型：运算数还是运算符，以及哪种运算符，type是如下的Token类变量之一：
        ```
        UNKNOWN  = 0        # unknown
        
        INT      = 4        # integer
                
        MINUS    = 5        # minus    operator
        PLUS     = 6        # plus     operator
        MUL      = 7        # multiply operator
        DIV      = 8        # divide   operator
        LPAR     = 9        # left par operator
        RPAR     = 10       # rightpar operator
        ```
    - value保存运算符数的值，或者预算符的字符串内容。

    包含构造函数，以及getType()、getValue()和isOperator()方法：
    - 构造函数Token(value):
        + 如果value是个整数，创建个Token.INT类型的Token对象
        + 否则创建个运算符类型的Token对象（根据运算符的字符串内容创建具体的运算符Token）

    - getType()：返回Token的类型
    - getValue()：返回Token的值。
    - isOperator()：判断Token是否为运算符。
    - getPrecedence()：返回运算符的优先级。

7. Stack类
    通用的栈容器实现，不做过多介绍，后面直接看代码。

### 程序的实现

下面按照设计中类的顺序给出Python实现代码，必要的地方会给出一些解释。

1. IFEvaluatorView类：IFEvaluatorView.py

```py
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
```

2. IFEvaluatorModel类：IFEvaluatorModel.py

```py
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
        result = str(self.converter)
        if self.evaluator:
            result += "\n" + str(self.evaluator)
        return result

def test_evaluator(evaluator, sourceStr):
    try:
        print(evaluator.format(sourceStr))
        print(evaluator.evaluate(sourceStr))
    except Exception as e:
        print(e)
        print(evaluator.evaluationStatus())

def main():
    # A simple tester program
    evaluator = IFEvaluatorModel()
    test_evaluator(evaluator, "8 + 2 * 3")
    test_evaluator(evaluator, "(8 + 2) * 3")
    test_evaluator(evaluator, "(8 + 2 * 3")
    test_evaluator(evaluator, "8 + 2) * 3")

if __name__ == "__main__":
    main()
```

3. IFToPFConverter类：IFToPFConverter.py

```py
#!/usr/bin/env python3

from Token import Token
from Scanner import Scanner
from Stack import Stack

class IFToPFConverter:

    def __init__(self, scanner):
        self.expressionSoFar = ""
        self.operatorStack = Stack()
        self.scanner = scanner

    def convert(self):
        """Returns a list of tokens that represent the postfix
        form of sourceStr.  Assumes that the infix expression
        in sourceStr is syntactically correct"""
        postfix = list()
        while self.scanner.hasNext():
            currentToken = self.scanner.next()
            self.expressionSoFar += str(currentToken) + " "
            if currentToken.getType() == Token.UNKNOWN:
                raise AttributeError("Unrecognized symbol")
            if currentToken.getType() == Token.INT:
                postfix.append(currentToken)
            elif currentToken.getType() == Token.LPAR:
                self.operatorStack.push(currentToken)
            elif currentToken.getType() == Token.RPAR:
                if self.operatorStack.isEmpty():
                    raise AttributeError("Too few operators(No matching opening left parenthese found)")
                topOperator = self.operatorStack.pop()
                while topOperator.getType() != Token.LPAR:
                    postfix.append(topOperator)
                    if self.operatorStack.isEmpty():
                        raise AttributeError("Too few operators(No matching opening left parenthese found)")
                    topOperator = self.operatorStack.pop()
            else:
                while not self.operatorStack.isEmpty() and \
                      self.operatorStack.peek().getPrecedence() >= currentToken.getPrecedence():
                    postfix.append(self.operatorStack.pop())
                self.operatorStack.push(currentToken)
        while not self.operatorStack.isEmpty():
            if self.operatorStack.peek().getType() == Token.LPAR:
                raise AttributeError("Too few operators(No matching opening right parenthese found)")
            postfix.append(self.operatorStack.pop())
        return postfix
   
    def __str__(self):
        result = ""
        if self.expressionSoFar == "":
            result += "Portion of infix expression processed: none\n"
        else: 
            result += "Portion of infix expression processed: " + \
                   self.expressionSoFar + "\n"
        if self.operatorStack.isEmpty():
            result += "The stack is empty"
        else:
            result += "Operators on the stack          : " + \
                      str(self.operatorStack)
        return result

    def conversionStatus(self):
        return str(self)

    
def main():
    while True:
        sourceStr = input("Enter an infix expression: ")
        if sourceStr == "":
            break
        else:
            try:
                converter = IFToPFConverter(Scanner(sourceStr))
                postfix = converter.convert()
                print("Postfix:", end = " ")
                for token in postfix:
                    print(token, end = " ")
                print()
            except Exception as e:
                print(e)
                print(converter.conversionStatus())

if __name__ == "__main__":
    main()
```

IFToPFConverter.convert()函数的具体步骤如下：
    1. 开始的时候，有一个空的后缀表达式（postfix）和一个空的栈（operatorStack），栈用来保存运算符和左括号。
    2. 从左向右扫描中缀表达式。
    3. 遇到一个运算数的时候，将其添加到后缀表达式的后面。
    4. 遇到一个左括号的时候，将其压入到栈中。
    5. 遇到一个运算符，从栈中弹出和它具有相等的或更高优先级的所有运算符，将它们添加到后缀表达式的末尾，然后，将扫描到的运算符压入到栈中。
    6. 遇到一个右括号的时候，将运算符从栈中移动到后缀表达式中，直到遇到了与之匹配的左括号，并将其丢弃。
    7. 遇到中缀表达式结束的时候，将栈中剩下的运算符都转移到后缀表达式之中。

表7.6和表7.7举例说明了这个过程。

![表7.6](table-7-6.png)

![表7.7](table-7-7.png)

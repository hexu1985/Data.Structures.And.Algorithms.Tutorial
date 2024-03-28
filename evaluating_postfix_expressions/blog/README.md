## 算术表达式计算程序：Python语言实现

本文介绍通过Python语言实现简单的算术表达式计算程序。
我们按照软件工程的基本步骤来介绍：
- 需求分析
- 设计
- 实现

### 程序的需求分析

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
- 当用户按下了Enter键之后，按照在每个标记之间只有一个空格的项是显示表达式，
- 在后面新的一行开始，紧跟着的是表达式的值或者错误消息，
- 用户通过在提示符直接按下Enter键来退出。

程序中检测并报告一些输入错误：
- 不匹配的括号，
- 表达式包含太少的运算数，
- 表达式包含太多的运算数，
- 表达式包含了不识别的标记：程序期待表达式包含整数、4中运算符（+、-、*、/）以及空白（空格和制表符）。任何其他内容都是不识别的。
- 表达式包含了除以0的情况。

### 程序的分析

我们计算算术表达式的处理过程主要分为两大步骤
- 将中缀表达式转化成等价的后缀表达式，
- 计算后缀表达式的结果

所以我们的设计中，首先想到的两个类是：
- IFToPFConverter类：中缀表达式转后缀表达式的类
- PFEvaluator类：计算后缀表达式的类

另外，将输入的一行表达式转换成标记序列的功能，也需要两个类：
- Token类：表示标记，包括运算数和运算符
- Scanner类：扫描一行字符串，转化成标记序列

另外还有一些辅助类和管理类：
- Stack类：栈类，中缀表达式转后缀表达式，以及后缀表达式的计算中都会用到
- IFEvaluatorModel类：算术表达式计算的功能类，驱动IFToPFConverter类和PFEvaluator类
- IFEvaluatorView类：用户交互界面类

具体的类关系图如下：

![表达式计算程序的类图](evaluate_class.png)





## 算术表达式计算：Python语言实现

本文介绍通过Python语言实现简单的算术表达式计算程序。

我们的程序中支持的算术表达式具有以下限制：
- 算术表达式采取中缀表示法（即日常的数学表达式）
- 运算数只支持正整数（负整数可以通过$0 - 正整数$获取）
- 运算符支持加、减、乘、除四则运算，优先级复合标准的四则运算
- 表达式支持括号`()`，支持嵌套的括号`()`

我们的程序具有如下功能：
- 允许用户一次输入一行算术表达式，然后程序会显示该表达式的值，
- 如果该表达式无效的话，则显示一条错误消息。

这是程序交互的一个示例：
```
Enter an infix expression: 12 + * 3
12 + * 3
Too few operands on the stack
Portion of expression processed: 12 + * 3
The stack is empty

Portion of expression processed: 12 3 * +
Operands on the stack          : [36]
Enter an infix expression: 12 - 4 * 5
12 - 4 * 5
-8
Enter an infix expression: (12 - 4) * 5
( 12 - 4 ) * 5
40
Enter an infix expression: (12 - 4 * 5
( 12 - 4 * 5
Too few operators(No matching opening right parenthese found)
Portion of expression processed: ( 12 - 4 * 5
Operators on the stack          : [(]

Enter an infix expression: 12 - 4) * 5
12 - 4 ) * 5
Too few operators(No matching opening left parenthese found)
Portion of expression processed: 12 - 4 )
The stack is empty

Enter an infix expression:
```

我们计算算术表达式的处理过程主要分为两大步骤
- 将中缀表达式转化成等价的后缀表达式，
- 计算后缀表达式的结果



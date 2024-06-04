#!/usr/bin/env python3

from linkedstack import LinkedStack as Stack

def test_stack1():
    mystack = Stack()
    sum = 0

    for i in range(1, 11):
        mystack.push(i)

    while not mystack.isEmpty():
        sum += mystack.pop()

    print("total:", sum)


def test_stack2():
    myints = Stack()
    print("0. size:", len(myints))

    for i in range(5):
        myints.push(i)
    print("1. size:", len(myints))

    myints.pop()
    print("2. size:", len(myints))

def test_stack3():
    reportStackSize = lambda s: print("{} elements on stack".format(len(s)))
    reportStackTop = lambda s: print("Top element:", s.peek())

    s = Stack()
    s.push(2)
    s.push(6)
    s.push(51)

    reportStackSize(s)
    reportStackTop(s)

    reportStackSize(s)
    s.pop()

    reportStackSize(s)
    reportStackTop(s)

def test_stack4():
    mystack = Stack()

    for i in range(5):
        mystack.push(i)

    print("Popping out elements...", end='')
    while not mystack.isEmpty():
        print(" {}".format(mystack.pop()), end='')
    print()

if __name__ == "__main__":
    test_stack1()
    test_stack2()
    test_stack3()
    test_stack4()

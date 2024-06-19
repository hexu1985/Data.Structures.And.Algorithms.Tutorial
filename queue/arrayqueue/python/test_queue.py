#!/usr/bin/env python3

from arrayqueue import ArrayQueue as Queue

def test_stack1():
    myqueue = Queue()
    sum = 0
    for i in range(1, 11):
        myqueue.add(i)

    while not myqueue.isEmpty():
        sum += myqueue.pop()

    print("total:", sum)

if __name__ == "__main__":
    test_stack1()

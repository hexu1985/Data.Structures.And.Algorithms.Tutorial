#!/usr/bin/env python3

from arrayqueue import ArrayQueue as Queue

def test_queue1():
    myqueue = Queue()
    sum = 0
    for i in range(1, 11):
        myqueue.add(i)

    while not myqueue.isEmpty():
        sum += myqueue.pop()

    print("total:", sum)

def test_queue2():
    myints = Queue()
    print("0. size:", len(myints))

    for i in range(5):
        myints.add(i)
    print("1. size:", len(myints))

    myints.pop()
    print("2. size:", len(myints))

if __name__ == "__main__":
    test_queue1()
    test_queue2()

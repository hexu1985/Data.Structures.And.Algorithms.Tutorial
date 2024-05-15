#!/usr/bin/env python3

from arrays import Array

def test_array1():
    myints = Array(5)
    print("size of myints:", len(myints))

def test_array2():
    myarray = Array(10)
    for i in range(10):
        myarray[i] = i

    print("myarray contains:", myarray)
    for i in range(i):
        print(myarray[i], end=' ')
    print()

def test_array3():
    myarray = Array(5)

    for i, val in enumerate([2, 16, 77, 34, 50]):
        myarray[i] = val

    print("myarray contains:", myarray)
    for val in myarray:
        print(val, end=' ')
    print()

if __name__ == "__main__":
    test_array1()
    test_array2()
    test_array3()

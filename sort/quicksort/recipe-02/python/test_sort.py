#!/usr/bin/env python3

from quicksort import quicksort
import random

def swap(a, i, j):
    temp = a[i]
    a[i] = a[j]
    a[j] = temp

def checkSort(a):
    for i in range(len(a)):
        if len(a[i]) != i:
            print("Error at", i)
    print("Finished checkSort")

def permute(a):
    for j in range(1, len(a)):
        swap(a, j, random.randint(0, j-1))

def main():
    NUM_ITEMS = 1000
    
    a = [""]*NUM_ITEMS

    for i in range(1, len(a)):
        a[i] = a[i-1] + 'a'

    for theSeed in range(10):
        permute(a)
        quicksort(a)
        checkSort(a)

    print("Checking SORT, Fig 7.13")
    N = NUM_ITEMS * NUM_ITEMS;
    b = [0] * N
    for i in range(N):
        b[i] = i
    permute(b)
    quicksort(b)

    for i in range(N):
        if b[ i ] != i: 
            print("OOPS!!")
    
if __name__ == "__main__":
    main()

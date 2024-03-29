#!/usr/bin/env python3

def quicksort(lyst):
    quicksortHelper(lyst, 0, len(lyst) - 1)

def quicksortHelper(lyst, left, right):
    if left >= right:
        return
    pivotLocation = partition(lyst, left, right)
    quicksortHelper(lyst, left, pivotLocation - 1)
    quicksortHelper(lyst, pivotLocation + 1, right)

def partition(lyst, left, right):
    pivot = lyst[right]
    i = left - 1
    j = right
    while True:
        while True:
            i = i + 1
            if lyst[i] >= pivot:
                break
        while True:
            j = j - 1
            if j == left or lyst[j] <= pivot:
                break
        if i < j:
            swap(lyst, i, j)
        else:
            break
    swap(lyst, i, right)
    return i

def swap(lyst, i, j):
    """Exchanges the items at positions i and j."""
    # You could say lyst[i], lyst[j] = lyst[j], lyst[i]
    # but the following code shows what is really going on
    temp = lyst[i]
    lyst[i] = lyst[j]
    lyst[j] = temp


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
    for j in range(left, right):    # left to right - 1
        if lyst[j] <= pivot:
            i = i + 1
            swap(lyst, i, j)
    swap(lyst, i + 1, right)
    return i + 1

def swap(lyst, i, j):
    """Exchanges the items at positions i and j."""
    # You could say lyst[i], lyst[j] = lyst[j], lyst[i]
    # but the following code shows what is really going on
    temp = lyst[i]
    lyst[i] = lyst[j]
    lyst[j] = temp


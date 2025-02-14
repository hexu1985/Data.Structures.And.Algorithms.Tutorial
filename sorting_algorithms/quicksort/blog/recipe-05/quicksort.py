#!/usr/bin/env python3

def quicksort(lyst):
    quicksortHelper(lyst, 0, len(lyst) - 1)

def quicksortHelper(lyst, left, right):
    if right - left <= 10:
        return insertionSort(lyst, left, right)
    pivotLocation = partition(lyst, left, right)
    quicksortHelper(lyst, left, pivotLocation - 1)
    quicksortHelper(lyst, pivotLocation + 1, right)

def partition(lyst, left, right):
    median3(lyst, left, right)

    pivot = lyst[right - 1]
    i = left
    j = right - 1
    while True:
        while True:
            i = i + 1
            if lyst[i] >= pivot:
                break
        while True:
            j = j - 1
            if lyst[j] <= pivot:
                break
        if i < j:
            swap(lyst, i, j)
        else:
            break
    swap(lyst, i, right - 1)
    return i

def median3(lyst, left, right):
    center = (left + right) // 2

    if lyst[center] < lyst[left]:
        swap(lyst, center, left)
    if lyst[right] < lyst[left]:
        swap(lyst, left, right)
    if lyst[right] < lyst[center]:
        swap(lyst, center, right)

    swap(lyst, center, right - 1)

def swap(lyst, i, j):
    """Exchanges the items at positions i and j."""
    # You could say lyst[i], lyst[j] = lyst[j], lyst[i]
    # but the following code shows what is really going on
    temp = lyst[i]
    lyst[i] = lyst[j]
    lyst[j] = temp

def insertionSort(lyst, left, right):
    i = left + 1
    while i <= right:
        itemToInsert = lyst[i]
        j = i - 1
        while j >= 0:
            if itemToInsert < lyst[j]:
                lyst[j + 1] = lyst[j]
                j -= 1
            else:
                break
        lyst[j + 1] = itemToInsert
        i += 1


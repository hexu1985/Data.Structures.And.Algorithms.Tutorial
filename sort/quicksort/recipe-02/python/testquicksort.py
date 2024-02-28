#!/usr/bin/env python3

"""
File: testquicksort.py

Tests the quicksort algorithm
"""

from quicksort import quicksort
import random

def main(size = 1000, sort = quicksort):
    lyst = []
    for count in range(size):
        lyst.append(random.randint(1, size + 1))
    print(lyst)
    sort(lyst)
    print(lyst)

if __name__ == "__main__":
    main() 

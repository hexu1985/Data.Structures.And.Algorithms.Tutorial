#!/usr/bin/env python3

from quicksort import quicksort
import random

def main():
    lyst = [2, 8, 7, 1, 3, 5, 6, 4]
    print(lyst)
    quicksort(lyst)
    print(lyst)

if __name__ == "__main__":
    main() 

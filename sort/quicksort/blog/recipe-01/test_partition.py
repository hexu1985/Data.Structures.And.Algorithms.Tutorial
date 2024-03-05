#!/usr/bin/env python3

from quicksort import partition
import random

def main():
    lyst = [2, 8, 7, 1, 3, 5, 6, 4]
    print(lyst)
    partition(lyst, 0, len(lyst)-1)
    print(lyst)

if __name__ == "__main__":
    main() 


#!/usr/bin/env python3

from quicksort import quicksort
import random

def main(size = 1000):
    lyst = []
    for count in range(size):
        lyst.append(random.randint(1, size + 1))

    answer = sorted(lyst)
    print(lyst)
    quicksort(lyst)
    print(lyst)

    if answer == lyst:
        print("quicksort is correct!")
    else:
        print("quicksort is not correct!")

if __name__ == "__main__":
    main() 

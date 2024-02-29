#!/usr/bin/env python3

import random

def main(size = 1000):
    lyst = []
    for count in range(size):
        lyst.append(random.randint(1, size + 1))
    print(lyst)
    lyst.sort()
    print(lyst)

if __name__ == "__main__":
    main() 

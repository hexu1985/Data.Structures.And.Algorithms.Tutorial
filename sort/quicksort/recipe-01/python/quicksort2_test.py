#!/usr/bin/env python3

from quicksort2 import quicksort

def main():
    """Tests with four lists."""
    lyst = [2, 4, 3, 0, 1, 5]
    quicksort(lyst)
    print(lyst)
    lyst = list(range(6))
    quicksort(lyst)
    print(lyst)

if __name__ == "__main__":
    main()
    


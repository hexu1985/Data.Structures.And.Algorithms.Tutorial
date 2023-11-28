#!/usr/bin/env python3

def swap(lyst, i, j):
    """Exchanges the items at positions i and j."""
    # You could say lyst[i], lyst[j] = lyst[j], lyst[i]
    # but the following code shows what is really going on
    temp = lyst[i]
    lyst[i] = lyst[j]
    lyst[j] = temp

def bubbleSortWithTweak(lyst):
    n = len(lyst)
    while n > 1:
        swapped = False
        i = 1
        while i < n:
            if lyst[i] < lyst[i - 1]:   # Exchange if needed
                swap(lyst, i, i - 1)
                swapped = True
            i += 1
        if not swapped: return          # Return if no swaps
        n -= 1

def main():
    """Tests with four lists."""
    lyst = [2, 4, 3, 0, 1, 5]
    bubbleSortWithTweak(lyst)
    print(lyst)
    lyst = list(range(6))
    bubbleSortWithTweak(lyst)
    print(lyst)

if __name__ == "__main__":
    main()
    


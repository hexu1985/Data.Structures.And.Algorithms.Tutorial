#!/usr/bin/env python3

def swap(lyst, i, j):
    """Exchanges the items at positions i and j."""
    # You could say lyst[i], lyst[j] = lyst[j], lyst[i]
    # but the following code shows what is really going on
    temp = lyst[i]
    lyst[i] = lyst[j]
    lyst[j] = temp

def bubbleSort(lyst):
    n = len(lyst)
    while n > 1:                        # Do n - 1 bubbles
        i = 1                           # Start each bubble
        while i < n:
            if lyst[i] < lyst[i - 1]:   # Exchange if needed
                swap(lyst, i, i - 1)
            i += 1
        n -= 1

def main():
    """Tests with four lists."""
    lyst = [2, 4, 3, 0, 1, 5]
    bubbleSort(lyst)
    print(lyst)
    lyst = list(range(6))
    bubbleSort(lyst)
    print(lyst)

if __name__ == "__main__":
    main()
    


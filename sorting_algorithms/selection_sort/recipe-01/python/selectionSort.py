#!/usr/bin/env python3

def swap(lyst, i, j):
    """Exchanges the items at positions i and j."""
    # You could say lyst[i], lyst[j] = lyst[j], lyst[i]
    # but the following code shows what is really going on
    temp = lyst[i]
    lyst[i] = lyst[j]
    lyst[j] = temp

def selectionSort(lyst):
    i = 0
    while i < len(lyst) - 1:    # Do n - 1 searches
        minIndex = i            # for the smallest
        j = i + 1
        while j < len(lyst):    # Start a search
            if lyst[j] < lyst[minIndex]:
                minIndex = j
            j += 1
        if minIndex != i:       # Exchange if needed
            swap(lyst, minIndex, i)
        i += 1

def main():
    """Tests with four lists."""
    lyst = [2, 4, 3, 0, 1, 5]
    selectionSort(lyst)
    print(lyst)
    lyst = list(range(6))
    selectionSort(lyst)
    print(lyst)

if __name__ == "__main__":
    main()
    


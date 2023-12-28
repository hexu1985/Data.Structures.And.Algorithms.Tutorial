#!/usr/bin/env python3

def insertionSort(lyst):
    i = 1
    while i < len(lyst):
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

def main():
    """Tests with four lists."""
    lyst = [2, 4, 3, 0, 1, 5]
    insertionSort(lyst)
    print(lyst)
    lyst = list(range(6))
    insertionSort(lyst)
    print(lyst)

if __name__ == "__main__":
    main()
    


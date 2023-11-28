"""
File: sort.py
Project 3.5

Allows the user to specify the direction of a selection sort.
"""

def selectionSort(lyst, reverse = False):
    """Sorts the list items in ascending order if
    reverse is False; otherwise, sorts 'em in
    descending order."""
    if not reverse:
        # Sort in ascending order, counting up
        i = 0
        while i < len(lyst) - 1:         # Do n - 1 searches
            minIndex = i                 # for the largest
            j = i + 1                    
            while j < len(lyst):         # Start a search
                if lyst[j] < lyst[minIndex]:
                    minIndex = j
                j += 1
            if minIndex != i:            # Exchange if needed
                swap(lyst, minIndex, i)
            i += 1
    else:
        # Sort in descending order, counting down
        i = len(lyst) - 1
        while i > 0:                     # Do n - 1 searches
            minIndex = i                 # for the largest
            j = i - 1                    
            while j >= 0:                # Start a search
                if lyst[j] < lyst[minIndex]:
                    minIndex = j
                j -= 1
            if minIndex != i:            # Exchange if needed
                swap(lyst, minIndex, i)
            i -= 1

def swap(lyst, x, y):
    """Exchanges the elements at positions x and y."""
    lyst[x], lyst[y] = lyst[y], lyst[x]


def main():
    """Tests with four lists."""
    lyst = [2, 4, 3, 0, 1, 5]
    selectionSort(lyst)
    print(lyst)
    lyst = list(range(6))
    selectionSort(lyst)
    print(lyst)
    lyst = [2, 4, 3, 0, 1, 5]
    selectionSort(lyst, reverse = True)
    print(lyst)
    lyst = list(range(6))
    selectionSort(lyst, reverse = True)
    print(lyst)

if __name__ == "__main__":
    main()
    


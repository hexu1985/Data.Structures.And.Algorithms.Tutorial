from typing import Any

def bubble_sort(lst: list[Any]) -> None:
    """Bubble sort"""
    for i in range(len(lst) - 1, 0, -1):
        exchanges = False
        for j in range(i):
            if lst[j] > lst[j + 1]:
                exchanges = True
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
        if not exchanges:
            break

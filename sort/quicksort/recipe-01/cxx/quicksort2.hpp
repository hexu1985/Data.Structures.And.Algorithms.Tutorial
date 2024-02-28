#pragma once

template <typename Container>
void swap(Container& lyst, int i, int j) {
    auto temp = lyst[i];
    lyst[i] = lyst[j];
    lyst[j] = temp;
}

template <typename Container>
int partition(Container& lyst, int left, int right) {
    int middle = (left + right) / 2;
    auto pivot = lyst[middle];
    lyst[middle] = lyst[right];
    lyst[right] = pivot;

    int boundary = left;
    for (int index = left; index < right; index++) {
        if (lyst[index] < pivot) {
            swap(lyst, index, boundary);
            boundary += 1;
        }
    }
    swap(lyst, right, boundary);
    return boundary;
}

template <typename Container>
void insertionSort(Container& lyst, int left, int right) {
    int i = left + 1;
    while (i <= right) {
        auto itemToInsert = lyst[i];
        int j = i - 1;
        while (j >= 0) {
            if (itemToInsert < lyst[j]) {
                lyst[j + 1] = lyst[j];
                j -= 1;
            } else {
                break;
            }
        }
        lyst[j + 1] = itemToInsert;
        i += 1;
    }
}

template <typename Container>
void quicksortHelper(Container& lyst, int left, int right) {
    if (right - left <= 50) {
        insertionSort(lyst, left, right);
    } else {
        int pivotLocation = partition(lyst, left, right);
        quicksortHelper(lyst, left, pivotLocation - 1);
        quicksortHelper(lyst, pivotLocation + 1, right);
    }
}

template <typename Container>
void quicksort(Container& lyst) {
    quicksortHelper(lyst, 0, lyst.size()-1);
}

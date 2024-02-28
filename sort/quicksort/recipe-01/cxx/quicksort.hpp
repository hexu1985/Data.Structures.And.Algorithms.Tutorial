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
void quicksortHelper(Container& lyst, int left, int right) {
    if (left < right) {
        int pivotLocation = partition(lyst, left, right);
        quicksortHelper(lyst, left, pivotLocation - 1);
        quicksortHelper(lyst, pivotLocation + 1, right);
    }
}

template <typename Container>
void quicksort(Container& lyst) {
    quicksortHelper(lyst, 0, lyst.size()-1);
}


#include <vector>
#include "sort_helper.hpp"

template <typename Container>
void swap(Container& lyst, int i, int j) {
    auto temp = lyst[i];
    lyst[i] = lyst[j];
    lyst[j] = temp;
}

template <typename Container>
void selection_sort(Container& lyst, bool reverse = false) {
    if (!reverse) {
        int i = 0;
        int n = lyst.size();
        while (i < n - 1) {
            int minIndex = i;
            int j = i + 1;
            while (j < n) {
                if (lyst[j] < lyst[minIndex]) {
                    minIndex = j;
                }
                j += 1;
            }
            if (minIndex != i) {
                swap(lyst, minIndex, i);
            }
            i += 1;
        }
    } else {
        int i = lyst.size() - 1;
        while (i > 0) {
            int minIndex = i;
            int j = i - 1;
            while (j >= 0) {
                if (lyst[j] < lyst[minIndex]) {
                    minIndex = j;
                }
                j -= 1;
            }
            if (minIndex != i) {
                swap(lyst, minIndex, i);
            }
            i -= 1;
        }
    }
}

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    selection_sort(lyst);
    print(lyst);

    range(lyst, 6);
    selection_sort(lyst);
    print(lyst);

    lyst = {2, 4, 3, 0, 1, 5};
    selection_sort(lyst, true);
    print(lyst);

    range(lyst, 6);
    selection_sort(lyst, true);
    print(lyst);
}

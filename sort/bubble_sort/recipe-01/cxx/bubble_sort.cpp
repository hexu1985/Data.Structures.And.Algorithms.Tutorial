#include <vector>
#include "sort_helper.hpp"

template <typename Container>
void swap(Container& lyst, int i, int j) {
    auto temp = lyst[i];
    lyst[i] = lyst[j];
    lyst[j] = temp;
}

template <typename Container>
void bubble_sort(Container& lyst) {
    int n = lyst.size();
    while (n > 1) {
        int i = 1;
        while (i < n) {
            if (lyst[i] < lyst[i - 1]) {
                swap(lyst, i, i - 1);
            }
            i += 1;
        }
        n -= 1;
    }
}

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    bubble_sort(lyst);
    print(lyst);

    range(lyst, 6);
    bubble_sort(lyst);
    print(lyst);
}

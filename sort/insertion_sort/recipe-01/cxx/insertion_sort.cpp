#include <vector>
#include "sort_helper.hpp"

template <typename Container>
void insertion_sort(Container& lyst) {
    int i = 1;
    int n = lyst.size();
    while (i < n) {
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

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    insertion_sort(lyst);
    print(lyst);

    range(lyst, 6);
    insertion_sort(lyst);
    print(lyst);
}

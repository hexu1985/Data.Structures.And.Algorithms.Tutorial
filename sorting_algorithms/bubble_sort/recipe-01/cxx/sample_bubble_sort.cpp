#include <vector>
#include "bubble_sort.hpp"
#include "sort_helper.hpp"

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    bubbleSort(lyst);
    print(lyst);

    range(lyst, 6);
    bubbleSort(lyst);
    print(lyst);
}

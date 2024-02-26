#include <vector>
#include "insertion_sort.hpp"
#include "sort_helper.hpp"

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    insertion_sort(lyst);
    print(lyst);

    range(lyst, 6);
    insertion_sort(lyst);
    print(lyst);
}

#include <vector>
#include "quicksort.hpp"
#include "sort_helper.hpp"

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    quicksort(lyst);
    print(lyst);

    range(lyst, 6);
    quicksort(lyst);
    print(lyst);
}

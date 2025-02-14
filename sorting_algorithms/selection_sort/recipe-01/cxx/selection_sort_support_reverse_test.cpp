#include <vector>
#include "selection_sort_support_reverse.hpp"
#include "sort_helper.hpp"

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

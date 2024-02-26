#include <vector>
#include "bubble_sort_with_tweak.hpp"
#include "sort_helper.hpp"

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    bubble_sort(lyst);
    print(lyst);

    range(lyst, 6);
    bubble_sort(lyst);
    print(lyst);
}

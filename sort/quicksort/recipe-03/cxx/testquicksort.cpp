#include <vector>
#include "quicksort.hpp"
#include "random.hpp"
#include "sort_helper.hpp"

int main() {
    int size = 1000;
    std::vector<int> lyst;
    Random random;
    for (int count = 0; count < size; count++) {
        lyst.push_back(random.randint(1, size + 1));
    }
    print(lyst);
    quicksort(lyst);
    print(lyst);
}

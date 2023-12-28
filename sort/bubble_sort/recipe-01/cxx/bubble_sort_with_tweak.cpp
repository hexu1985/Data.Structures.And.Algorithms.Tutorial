
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
        bool swapped = false;
        int i = 1;
        while (i < n) {
            if (lyst[i] < lyst[i - 1]) {
                swap(lyst, i, i - 1);
                swapped = true;
            }
            i += 1;
        }
        if (!swapped) return;
        n -= 1;
    }
}

#include <iostream>
#include <numeric>

template <typename Container>
void print(Container& lyst) {
    std::cout << "[ ";
    for (const auto& item : lyst) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

template <typename Container>
void range(Container& arr, int n) {
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

#include <vector>

int main() {
    std::vector<int> lyst = {2, 4, 3, 0, 1, 5};
    bubble_sort(lyst);
    print(lyst);

    range(lyst, 6);
    bubble_sort(lyst);
    print(lyst);
}

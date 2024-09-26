#include <iostream>
#include <string>
#include <algorithm>
#include "random.hpp"

Random my_random{0};
bool dump = true;

std::vector<int> generate_vector(int size) {
    int min = 1;
    int max = 1000;
    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(my_random.randint(min, max));
    }
    return vec;
}

void print_vector(std::vector<int>& vec) {
    for (auto& i : vec) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

void n_way_merge(std::vector<int>& out, const std::vector<std::vector<int>>& queues) {
    out.clear();
    for (auto& q : queues) {
        for (auto& v : q) {
            out.push_back(v);
        }
    }
    std::sort(out.begin(), out.end());
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "usage: " << argv[0] << " <number_of_queue> <queue_size> \n"
                << "\texample: " << argv[0] << " 3 20" << std::endl;
        return 1;
    }

    int number_of_queue = std::stoi(argv[1]);
    int queue_size = std::stoi(argv[2]);

    if (number_of_queue < 2) {
        std::cout << "invalid number_of_queue: " << number_of_queue
            << ", must >= 2" << std::endl;
        return 1;
    }

    if (queue_size < 1) {
        std::cout << "invalid queue_size: " << queue_size
            << ", must >= 1" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> queues;
    for (int i = 0; i < number_of_queue; i++) {
        std::vector<int> vec = generate_vector(queue_size);
        std::sort(vec.begin(), vec.end());
        if (dump) {
            std::cout << "input[" << i+1 << "]: ";
            print_vector(vec);
        }
        queues.push_back(vec);
    }

    std::vector<int> result;
    n_way_merge(result, queues);
    if (dump) {
        std::cout << "result: ";
        print_vector(result);
    }

    if (std::is_sorted(result.begin(), result.end())) {
        std::cout << "merge success!" << std::endl;
    } else {
        std::cout << "merge failed!" << std::endl;
    }

    return 0;
}
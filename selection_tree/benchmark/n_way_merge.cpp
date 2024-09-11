#include <iostream>
#include <string>

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


}

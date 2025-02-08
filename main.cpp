#include <iostream>
#include "Array.h"

template <typename T>
void printArray(const Array<T>& arr) {

    for (auto it = arr.begin(); it != arr.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}


int main() {
    Array<int> arr(10);


    arr.append(10);
    arr.append(20);
    arr.append(30);

    std::cout << "Array elements: ";
    printArray(arr);

    arr.insert(15, 1);
    std::cout << "After inserting 15 at index 1: ";
    printArray(arr);

    arr.erase(2);
    std::cout << "After erasing index 2: ";
    printArray(arr);

    arr.sort();
    std::cout << "After sorting: ";
    printArray(arr);

    std::cout << "Size of array: " << arr.size() << "\n";
    std::cout << "Capacity of array: " << arr.capacity() << "\n";

    arr.shrink_to_fit();

    std::cout << "Capacity of array after shrink_to_fit: " << arr.capacity() << "\n";

    arr.clear();

    std::cout << "Size of array after clear: " << arr.size() << "\n";
    std::cout << "Array elements: ";
    printArray(arr);
    
    Array<int> init = {1, 2, 3, 4, 5};
    
    std::cout << "Initialized with initializer constructor: ";
    printArray(init);


    return 0;
}

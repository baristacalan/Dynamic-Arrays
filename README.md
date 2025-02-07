# Dynamic Array Implementation in C++

## Overview

This is a C++ implementation of a **dynamic array** (similar to `std::vector`) that provides functionalities such as appending, inserting, erasing, sorting, and resizing elements dynamically. The class supports both **deep copy constructio**n and copy assignment to prevent memory management issues.

## Features

- **Dynamic memory management** (automatic resizing)
- **Deep copy support** (prevents shallow copy issues)
- **Appending and inserting elements**
- **Removing elements** by index
- **Sorting elements**
- **Shrinking capacity to fit the number of elements**
- **Iterator support** (`begin()` and `end()` functions for range-based loops)
- **Operator overloading** (`[]` for element access)

## Installation

To use this dynamic array class in your project:

1. Clone or download this repository.
2. Include `Array.h` and `Array.tpp` in your project.
3. Compile your program with a C++ compiler.

## Usage

### **Including and Using the Dynamic Array**

```cpp
#include "Array.h"
#include <iostream>

int main() {
    Array<int> arr(10);

    arr.append(10);
    arr.append(20);
    arr.append(30);

    std::cout << "Array elements: ";
    for (auto it = arr.begin(); it != arr.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
```

### **Methods Available**

```cpp
// Constructor
Array<T> arr(size_t capacity = 32);

// Append elements
arr.append(42);

// Insert at a specific position
arr.insert(15, 1);

// Erase an element by index
arr.erase(2);

// Get element by index
int value = arr.at(1);

// Sort array
arr.sort();

// Get size and capacity
size_t sz = arr.size();
size_t cap = arr.capacity();

// Shrink capacity to fit size
arr.shrink_to_fit();

// Clear the array
arr.clear();
```

### **Iterating Through the Array**

Using iterators:

```cpp
for (auto it = arr.begin(); it != arr.end(); it++) {
    std::cout << *it << " ";
}
```

Or using a range-based for loop:

```cpp
for (const auto& elem : arr) {
    std::cout << elem << " ";
}
```

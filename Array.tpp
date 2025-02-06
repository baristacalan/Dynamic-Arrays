#pragma once
#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.h"

// Constructor
template <typename T>
Array<T>::Array(size_t capacity) 
    : m_capacity(capacity), m_size(0) {
    m_items = new T[m_capacity];
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] m_items;
}

// Grow capacity dynamically
template <typename T>
void Array<T>::grow() {
    reallocate(m_capacity * 2);
}

// Resize array with new capacity
template <typename T>
void Array<T>::reallocate(size_t new_capacity) {
    T* temp = new T[new_capacity];
    for (size_t i = 0; i < m_size; i++) {
        temp[i] = std::move(m_items[i]);
    }
    delete[] m_items;
    m_items = temp;
    m_capacity = new_capacity;
}

// Append new element
template <typename T>
void Array<T>::append(const T& element) {
    if (m_size >= m_capacity) grow();
    m_items[m_size++] = element;
}

// Erase element at given index
template <typename T>
void Array<T>::erase(size_t index) {
    if (index >= m_size) {
        std::cerr << "Invalid index!\n";
        return;
    }
    for (size_t i = index; i < m_size - 1; i++) {
        m_items[i] = std::move(m_items[i + 1]);
    }
    --m_size;
}

// Clear array
template <typename T>
void Array<T>::clear() {
    delete[] m_items;
    m_capacity = 32;
    m_size = 0;
    m_items = new T[m_capacity];
}

// Sort array
template <typename T>
void Array<T>::sort() {
    std::sort(m_items, m_items + m_size);
}

// Resize array
template <typename T>
void Array<T>::resize(size_t capacity) {
    if (capacity < m_size) {
        std::cerr << "Capacity too small!\n";
        return;
    }
    reallocate(capacity);
}

// Shrink array to fit actual size
template <typename T>
void Array<T>::shrink_to_fit() {
    reallocate(m_size);
}

// Insert element at index
template <typename T>
void Array<T>::insert(const T& element, size_t index) {
    if (index > m_size) {
        std::cerr << "Invalid index!\n";
        return;
    }
    if (m_size >= m_capacity) grow();
    for (size_t i = m_size; i > index; --i) {
        m_items[i] = std::move(m_items[i - 1]);
    }
    m_items[index] = element;
    ++m_size;
}

// Swap two elements
template <typename T>
void Array<T>::swap(size_t first_index, size_t second_index) {
    if (first_index >= m_size || second_index >= m_size) {
        std::cerr << "Invalid indices!\n";
        return;
    }
    std::swap(m_items[first_index], m_items[second_index]);
}

// Print elements
template <typename T>
void Array<T>::print() const {
    if (isEmpty()) {
        std::cout << "Array empty!\n";
        return;
    }
    for (size_t i = 0; i < m_size; i++) {
        std::cout << m_items[i] << " ";
    }
    std::cout << "\n";
}

// Get element at index with bounds checking
template <typename T>
const T& Array<T>::at(size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_items[index];
}

// Get array size
template <typename T>
size_t Array<T>::size() const {
    return m_size;
}

// Get array capacity
template <typename T>
size_t Array<T>::capacity() const {
    return m_capacity;
}

// Check if array is empty
template <typename T>
bool Array<T>::isEmpty() const {
    return m_size == 0;
}

// Begin index
template <typename T>
size_t Array<T>::begin() {
    return 0;
}

// End index
template <typename T>
size_t Array<T>::end() {
    return -1;
}

// Operator overload for index access
template <typename T>
T& Array<T>::operator[](size_t index) {

    if (index >= m_capacity) {
        reallocate(index + 1);
    }
    if (index >= m_size) {
        m_size = index + 1;  // Automatically expand the size
    }
    return m_items[index];
}


#endif //!ARRAY_TPP
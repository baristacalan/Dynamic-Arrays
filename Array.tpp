#include "Array.h"

// ---->Constructors<----

template <typename T>
Array<T>::Array(size_t capacity) : m_size(0), m_capacity(capacity) {
    m_items = new T[m_capacity]; // Allocate memory for the array
}

template <typename T>
Array<T>::Array(std::initializer_list<T> init) 
: m_size(init.size()), m_capacity(init.size()) {
    
    m_items = new T[m_capacity];
    size_t i = 0;
    for(const T& elm : init) {
        
        m_items[i++] = elm;
    }

}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array& other)
    : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_items = new T[m_capacity]; // Allocate new memory
    for (size_t i = 0; i < m_size; i++) {
        m_items[i] = other.m_items[i]; // Copy each element
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] m_items; // Free allocated memory
}

template <typename T>
void Array<T>::append(const T& element) {
    if (m_size == m_capacity) {
        grow(); // Expand array if needed
    }
    m_items[m_size++] = element;
}

template <typename T>
void Array<T>::erase(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < m_size - 1; i++) {
        m_items[i] = m_items[i + 1]; // Shift elements to the left
    }
    m_size--;
}

template <typename T>
void Array<T>::clear() {
    m_size = 0; // Reset size without deallocating memory
}

template <typename T>
void Array<T>::sort() {
    std::sort(m_items, m_items + m_size); // Standard sort algorithm
}

template <typename T>
void Array<T>::resize(size_t capacity) {
    if (capacity < m_size) {
        m_size = capacity; // Truncate array if reducing capacity
    }
    reallocate(capacity);
}

template <typename T>
void Array<T>::shrink_to_fit() {
    reallocate(m_size);
}

template <typename T>
void Array<T>::insert(const T& element, size_t index) {
    if (index > m_size) {
        throw std::out_of_range("Index out of range");
    }
    if (m_size == m_capacity) {
        grow();
    }
    for (size_t i = m_size; i > index; i--) {
        m_items[i] = m_items[i - 1]; // Shift elements to the right
    }
    m_items[index] = element;
    m_size++;
}

template <typename T>
void Array<T>::swap(size_t first_index, size_t second_index) {
    if (first_index >= m_size || second_index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    std::swap(m_items[first_index], m_items[second_index]);
}

template <typename T>
const T& Array<T>::at(size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_items[index];
}

template <typename T>
size_t Array<T>::size() const {
    return m_size;
}

template <typename T>
size_t Array<T>::capacity() const {
    return m_capacity;
}

template <typename T>
bool Array<T>::isEmpty() const {
    return m_size == 0;
}

template <typename T>
void Array<T>::grow() {
    reallocate(m_capacity * 2); // Double the capacity when growing
}

template <typename T>
void Array<T>::reallocate(size_t new_capacity) {
    T* new_items = new T[new_capacity];
    for (size_t i = 0; i < m_size; i++) {
        new_items[i] = m_items[i];
    }
    delete[] m_items;
    m_items = new_items;
    m_capacity = new_capacity;
}

// ---->Iterators<----

template<typename T>
T* Array<T>::begin() {
    return m_items;
}

template <typename T>
T* Array<T>::end() {
    return m_items + m_size;
}
template<typename T>
const T* Array<T>::begin() const {
    return m_items;
}

template <typename T>
const T* Array<T>::end() const{
    return m_items + m_size;
}

//---->Operators<----

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_items[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const{
    if(index >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    return m_items[index];
}

// Copy Assignment Operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Free existing memory
    delete[] m_items;

    // Copy new data
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_items = new T[m_capacity];
    for (size_t i = 0; i < m_size; i++) {
        m_items[i] = other.m_items[i]; // Copy each element
    }

    return *this;
}
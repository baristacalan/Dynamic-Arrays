#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>

template <typename T>
class Array {
private:
    T* m_items;
    size_t m_size;
    size_t m_capacity;

    void grow();
    void reallocate(size_t new_capacity);

public:
    explicit Array(size_t capacity = 32);
    ~Array();

    void append(const T& element);
    void erase(size_t index);
    void clear();
    void sort();
    void resize(size_t capacity);
    void shrink_to_fit();
    void insert(const T& element, size_t index);
    void swap(size_t first_index, size_t second_index);

    void print() const;

    const T& at(size_t index) const;
    static size_t begin();
    static size_t end();

    size_t size() const;
    size_t capacity() const;
    bool isEmpty() const;

    // Operators
    T& operator[](size_t index);
};

#include "Array.tpp"

#endif

#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <stdexcept>

/**
 * @brief A dynamic array implementation in C++.
 *
 * This class provides a dynamically allocated array with features
 * such as appending, resizing, inserting, swapping, sorting, and more.
 */
template <typename T>
class Array {

private:
    T* m_items;        ///< Pointer to the dynamically allocated array
    size_t m_size;     ///< Current number of elements in the array
    size_t m_capacity; ///< Total allocated capacity of the array

    /**
     * @brief Increases the capacity of the array when needed.
     */
    void grow();

    /**
     * @brief Reallocates the array to a new capacity.
     * @param new_capacity The new capacity to allocate.
     */
    void reallocate(size_t new_capacity);

public:
    /**
     * @brief Constructs an array with an optional initial capacity.
     * @param capacity Initial capacity of the array (default is 32).
     */
    explicit Array(size_t capacity = 32);
    
    /**
    * @brief Initialization constructor for direct manual initialization.
    * @param Initialization items as type T.
    */
    Array(std::initializer_list<T> init);

    /**
    * @brief Copy constructor for deep copying the Array.
    * @param other The Array to copy from.
    */
    Array(const Array& other);

    /**
     * @brief Copy assignment operator for deep copying the Array.
     * @param other The Array to copy from.
     * @return A reference to the current object.
     */
    Array& operator=(const Array& other);

    /**
     * @brief Destructor to free allocated memory.
     */
    ~Array();

    /**
     * @brief Adds an element to the end of the array.
     * @param element The element to append.
     */
    void append(const T& element);

    /**
     * @brief Removes an element at a given index.
     * @param index The index of the element to remove.
     * @throws std::out_of_range if index is invalid.
     */
    void erase(size_t index);

    /**
     * @brief Clears all elements in the array.
     */
    void clear();

    /**
     * @brief Sorts the elements in ascending order.
     */
    void sort();

    /**
     * @brief Resizes the array to a new capacity.
     * @param capacity The new capacity to allocate.
     */
    void resize(size_t capacity);

    /**
     * @brief Shrinks the array's capacity to match its size.
     */
    void shrink_to_fit();

    /**
     * @brief Inserts an element at a specific index.
     * @param element The element to insert.
     * @param index The position where the element should be inserted.
     */
    void insert(const T& element, size_t index);

    /**
     * @brief Swaps the positions of two elements.
     * @param first_index The index of the first element.
     * @param second_index The index of the second element.
     * @throws std::out_of_range if indexes are invalid.
     */
    void swap(size_t first_index, size_t second_index);

    /**
     * @brief Accesses an element at a given index (read-only).
     * @param index The index to access.
     * @return const T& Reference to the element at the index.
     * @throws std::out_of_range if index is out of bounds.
     */
    const T& at(size_t index) const;

    /**
     * @brief Returns the start index address.
     */
    T* begin();
    const T* begin() const;

    /**
     * @brief Returns the end index address.
     */
    T* end();
    const T* end() const;

    /**
     * @brief Returns the current size of the array.
     * @return Number of elements in the array.
     */
    size_t size() const;

    /**
     * @brief Returns the total capacity of the array.
     * @return The allocated capacity.
     */
    size_t capacity() const;

    /**
     * @brief Checks if the array is empty.
     * @return True if the array is empty, false otherwise.
     */
    bool isEmpty() const;

    // Operators

    /**
     * @brief Provides indexed access to elements.
     * @param index The index to access.
     * @return Reference to the element at the index.
     * @throws std::out_of_range if index is out of bounds.
     */
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

#include "Array.tpp"

#endif

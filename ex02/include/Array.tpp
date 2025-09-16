#include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array()
    : _size(0), _data(nullptr) {}

// n elements default-initialized
template <typename T>
Array<T>::Array(unsigned int n)
    : _size(n), _data(nullptr) {
    if (_size > 0) {
        _data = new T[_size];
    }
}

// Copy constructor (deep copy)
template <typename T>
Array<T>::Array(const Array& other)
    : _size(other._size), _data(nullptr) {
    if (_size > 0) {
        _data = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
}

// Assignment operator (deep copy)
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other)
        return *this;

    // allocate new memory first
    T* newData = nullptr;
    if (other._size > 0) {
        newData = new T[other._size];
        for (size_t i = 0; i < other._size; ++i)
            newData[i] = other._data[i];
    }
	// free old
    delete[] _data;
    _data = newData;
    _size = other._size;
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

// operator[] with bounds checking
template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size)
        throw std::out_of_range("Array index is out of range");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= _size)
        throw std::out_of_range("Array index is out of range");
    return _data[index];
}

template <typename T>
size_t Array<T>::size() const {
    return _size;
}

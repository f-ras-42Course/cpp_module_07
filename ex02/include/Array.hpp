#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    
    // Access with bounds checking
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    size_t size() const;
    
    private:
    size_t _size;
    T* _data;
};

#include "Array.tpp"

#endif

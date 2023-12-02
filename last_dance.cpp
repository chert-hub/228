#include <algorithm>
#include <iostream>
#include <stdexcept>



template <typename T> class Vector {
private:
    T* data;
    std::size_t capacity;
    std::size_t length;

public:
    

    Vector() : data(nullptr), capacity(0), length(0) {}

    

    Vector(std::size_t size) : data(new T[size]), capacity(size), length(size) {}

    

    Vector(const Vector& other)
        : data(new T[other.capacity]), capacity(other.capacity),
        length(other.length) {
        std::copy(other.data, other.data + length, data);
    }

    

    Vector(Vector&& other) noexcept : data(nullptr), capacity(0), length(0) {
        swap(other);
    }

    

    ~Vector() { delete[] data; }

    

    Vector& operator=(const Vector& other) {

        

        if (this != &other) {

            

            delete[] data;

            

            capacity = other.capacity;
            length = other.length;

            

            data = new T[capacity];
            std::copy(other.data, other.data + length, data);
        }

      

        return *this;
    }

    

    Vector& operator=(Vector&& other) noexcept {

        

        swap(other);

        

        return *this;
    }


    void push_back(const T& value) {

        

        if (length == capacity) {

            

            reserve(capacity == 0 ? 1 : capacity * 2);
        }

        

        data[length++] = value;
    }

    

    void pop_back() {
        if (length > 0) {
            --length;
        }
    }

  

    T& operator[](std::size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    

    T& front() {
        if (length == 0) {
            throw std::length_error("Vector is empty");
        }
        return data[0];
    }

    const T& front() const {
        if (length == 0) {
            throw std::length_error("Vector is empty");
        }
        return data[0];
    }

    T& back() {
        if (length == 0) {
            throw std::length_error("Vector is empty");
        }
        return data[length - 1];
    }

    const T& back() const {
        if (length == 0) {
            throw std::length_error("Vector is empty");
        }
        return data[length - 1];
    }

    

    bool empty() const { return length == 0; }

    

    std::size_t size() const { return length; }

    

    const T* getData() const { return data; }

    void swap(Vector& other) noexcept {
        std::swap(data, other.data);
        std::swap(capacity, other.capacity);
        std::swap(length, other.length);
    }

    

    void reserve(std::size_t newCapacity) {

        

        if (newCapacity > capacity) {

            

            T* newData = new T[newCapacity];

            

            std::copy(data, data + length, newData);

            

            delete[] data;

            

            data = newData;

            

            capacity = newCapacity;
        }
    }

    

    void resize(std::size_t newSize) {

        

        if (newSize > capacity) {

            

            reserve(newSize);
        }

      

        length = newSize;
    }
};

template <typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) {
    Vector<T> result(v1.size() + v2.size());

   
    for (std::size_t i = 0; i < v1.size(); ++i) {
        result[i] = v1[i];
    }

   
    for (std::size_t i = 0; i < v2.size(); ++i) {
        result[v1.size() + i] = v2[i];
    }

    return result;
}

template <typename T> Vector<T> operator*(const Vector<T>& v, size_t n) {
    Vector<T> result(v.size() * n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < v.size(); ++j) {
            result[i * v.size() + j] = v[j];
        }
    }
    return result;
}

int main() {
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    Vector<int> v2 = v1;
    v2.pop_back();
    Vector<int> v3 = v1 + v2;
    Vector<int> v4 = v1 * 3;

    for (std::size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < v3.size(); ++i) {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < v4.size(); ++i) {
        std::cout << v4[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
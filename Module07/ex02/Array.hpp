#pragma once
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* data;
        unsigned int size;

    public:
        Array() : data(NULL), size(0) {}

        Array(unsigned int n) : data(new T[n]()), size(n) {}

        Array(const Array& other) : data(NULL), size(0)
        {
            if (other.size > 0)
            {
                data = new T[other.size]();
                for (unsigned int i = 0; i < other.size; i++)
                    data[i] = other.data[i];
                size = other.size;
            }
        }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] data;
                size = other.size;
                if (size > 0)
                {
                    data = new T[size]();
                    for (unsigned int i = 0; i < size; i++)
                        data[i] = other.data[i];
                }
                else
                    data = NULL;
            }
            return *this;
        }

        ~Array()
        {
            delete[] data;
        }

        T& operator[](unsigned int index)
        {
            if (index >= size)
                throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        const T& operator[](unsigned int index) const
        {
             if (index >= size)
                throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        unsigned int getSize() const
        {
            return size;
        }
};

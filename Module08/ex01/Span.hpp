#pragma once
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) > static_cast<long>(_maxSize - _numbers.size()))
                throw std::exception();
            _numbers.insert(_numbers.end(), begin, end);
        }

        int shortestSpan() const;
        int longestSpan() const;

        class FullException : public std::exception {
            public: virtual const char* what() const throw();
        };

        class NoSpanException : public std::exception {
            public: virtual const char* what() const throw();
        };
};

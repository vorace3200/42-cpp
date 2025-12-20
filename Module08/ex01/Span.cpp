#include "Span.hpp"
#include <limits>
#include <iostream>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {
    _numbers.reserve(n);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw Span::FullException();
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw Span::NoSpanException();
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        int span = sorted[i+1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw Span::NoSpanException();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    
    return maxVal - minVal;
}

const char* Span::FullException::what() const throw() {
    return "Span is full";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to find a span";
}

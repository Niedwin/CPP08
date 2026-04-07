/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:35:08 by guviure           #+#    #+#             */
/*   Updated: 2026/04/03 14:29:33 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();

    _numbers.push_back(n);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw NoSpanException();

    std::vector<int> copy = _numbers;

    std::sort(copy.begin(), copy.end());

    unsigned int min = copy[1] - copy[0];

    for (size_t i = 1; i < copy.size() - 1; i++)
    {
        unsigned int diff = copy[i + 1] - copy[i];

        if (diff < min)
            min = diff;
    }

    return min;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw NoSpanException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

const char* Span::SpanFullException::what() const throw()
{
    return "Span is full";
}

const char* Span::NoSpanException::what() const throw()
{
    return "Not enough numbers to find span";
}


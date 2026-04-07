/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:35:10 by guviure           #+#    #+#             */
/*   Updated: 2026/04/07 15:46:55 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>

class Span
{
private:

    unsigned int _maxSize;
    std::vector<int> _numbers;

public:

    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class SpanFullException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class NoSpanException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:17:26 by guviure           #+#    #+#             */
/*   Updated: 2026/04/07 14:57:49 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>

int main()
{
    try
    {
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
            vec.push_back(i * 2); 

        std::cout << "Testing vector:" << std::endl;
        int to_find = 6;
        std::vector<int>::iterator it_vec = easyfind(vec, to_find);
        std::cout << "Found " << *it_vec << " in vector at position "
                  << std::distance(vec.begin(), it_vec) << std::endl;

        to_find = 7;
        it_vec = easyfind(vec, to_find);
        std::cout << "Found " << *it_vec << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::list<int> lst;
        for (int i = 5; i < 15; i++)
            lst.push_back(i);

        std::cout << "Testing list:" << std::endl;
        int to_find = 10;
        std::list<int>::iterator it_lst = easyfind(lst, to_find);
        std::cout << "Found " << *it_lst << " in list" << std::endl;

        to_find = 20;
        it_lst = easyfind(lst, to_find);
        std::cout << "Found " << *it_lst << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
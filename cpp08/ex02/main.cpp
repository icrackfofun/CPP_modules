/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:44:58 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/11 18:03:02 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Basic stack behavior ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;     // 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n=== Forward iteration ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n=== Reverse iteration ===" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\n=== Modify through iterator ===" << std::endl;
    for (MutantStack<int>::iterator mit = mstack.begin(); mit != mstack.end(); ++mit)
        *mit += 10;

    for (MutantStack<int>::iterator mit = mstack.begin(); mit != mstack.end(); ++mit)
        std::cout << *mit << " ";
    std::cout << std::endl;

    std::cout << "\n=== Const iterator test ===" << std::endl;
    const MutantStack<int> constStack(mstack);
    for (MutantStack<int>::const_iterator cit = constStack.begin(); 
         cit != constStack.end(); ++cit)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Compatibility with std::stack ===" << std::endl;
    std::stack<int> s(mstack); // Should work fine
    std::cout << "std::stack top = " << s.top() << std::endl;

    return 0;
}

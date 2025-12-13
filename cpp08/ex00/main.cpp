#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testFind(const std::string &label)
{
    std::cout << "\n=== " << label << " ===\n";
}

int main() {
    testFind("std::vector<int>");
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    try {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        easyfind(v, 999);
    } catch (std::exception &e) {
        std::cout << "Not found: " << e.what() << std::endl;
    }

    testFind("std::list<int>");
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    try {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    testFind("std::deque<int>");
    std::deque<int> dq;
    dq.push_back(1);
	dq.push_back(2);
    dq.push_back(3);
    try {
        std::deque<int>::iterator it = easyfind(dq, 2);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

	return 0;
}
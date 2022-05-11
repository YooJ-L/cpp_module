#include "easyfind.hpp"
#include <iostream>
#include <exception>
#include <list>
#include <vector>
#include <deque>

int		main(void)
{
	std::list<int> l;
	std::vector<int> v;
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
		v.push_back(i);
		d.push_back(i);
	}

	try {
		for (int i = 1; i < 10; i += 2)
		{
			std::cout << *easyfind(l, i) << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << "\n===== [ list ] =====" << std::endl;
		easyfind(l, 123);
	} catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "\n===== [ vector ] =====" << std::endl;
		easyfind(v, 300);
	} catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "\n===== [ deque ] =====" << std::endl;
		easyfind(d, 10);
	} catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
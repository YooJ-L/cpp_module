#include <vector>
#include <algorithm>
#include "Span.hpp"

#define CAPACITY 10000

int		main(void)
{
	{
		std::cout << "===== Subject =====" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	std::cout << "\n===== Exception Test =====" << std::endl;
	try {
		Span one(1);
		one.addNumber(32);
		std::cout << one.shortestSpan() << std::endl;

		Span two(2);
		two.addNumber(20);
		two.addNumber(2);
		std::cout << two.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n===== Large Size Case =====" << std::endl;
	try {
		Span span(30000);
		std::vector<int> temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i);
		for (int i = 10; i < CAPACITY; i++)
			temp.push_back(10);
		std::cout << "size: " << temp.size() << std::endl;
		span.addNumber(temp.begin(), temp.end());
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

		std::cout << "\n===== Copy Test =====" << std::endl;
		Span copy = span;
		std::cout << copy.shortestSpan() << std::endl;
		std::cout << copy.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
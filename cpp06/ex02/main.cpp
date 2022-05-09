#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base*	generate(void)
{
	std::srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			std::cout << "[ A ] is created" << std::endl;
			return new A();
		case 1:
			std::cout << "[ B ] is created" << std::endl;
			return new B();
		case 2:
			std::cout << "[ C ] is created" << std::endl;
			return new C();
		default:
			return NULL;		
	}
}

void	identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << "ERROR: ptr is NULL" << std::endl;
		return ;
	}
	if (dynamic_cast<A *>(p))
		std::cout << "The Class is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The Class is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The Class is C" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
}

void	identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "The Class is A\n";
	} catch (const std::exception &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "The Class is B\n";
	} catch (const std::exception &e) {}

	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "The Class is C\n";
	} catch (const std::exception &e) {}
}

int		main(void)
{
	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;
	return (0);
}
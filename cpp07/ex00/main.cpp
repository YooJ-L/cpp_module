#include "whatever.hpp"

int		main(void)
{
	{
	std::cout << "===== SUBJECT =====\n";
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	
	std::cout << "\n===== INT =====\n";
	int	a = 1;
	int	b = 5;

	::swap(a,b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "max(a,b) = " << ::max(a,b) << std::endl;
	std::cout << "min(a,b) = " << ::min(a,b) << std::endl;

	std::cout << "\n===== CHAR =====\n";
	char c = 'c';
	char d = 'd';

	::swap(c,d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "max(c,d) = " << ::max(c,d) << std::endl;
	std::cout << "min(c,d) = " << ::min(c,d) << std::endl;

	std::cout << "\n===== DOUBLE =====\n";
	double e = 99.9;
	double f = 100.9;
	::swap(e,f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "max(e,f) = " << ::max(e,f) << std::endl;
	std::cout << "min(e,f) = " << ::min(e,f) << std::endl;

	std::cout << "\n===== STRING =====\n";
	std::string g = "GhelloG";
	std::string h = "HhelloH";
	::swap(g,h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "max(g,h) = " << ::max(g,h) << std::endl;
	std::cout << "min(g,h) = " << ::min(g,h) << std::endl;
}
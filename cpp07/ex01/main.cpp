#include "iter.hpp"

int		main(void)
{
	int	integerArr[5] = {0, 1, 2, 3, 4};
	std::string strArr[3] = {"hello", "world", "people"};
	char	charArr[4] = {'c', '+', 'A', 'k'};
	double	doubleArr[6] = {1.1, 3.3, 5.5, 7.7, 9.9, 10.11};

	std::cout << "\nINT" << std::endl;
	iter(integerArr, sizeof(integerArr) / sizeof(int), print);

	std::cout << "\nSTRING" << std::endl;
	iter(strArr, sizeof(strArr) / sizeof(std::string), print);

	std::cout << "\nCHAR" << std::endl;
	iter(charArr, sizeof(charArr) / sizeof(char), print);

	std::cout << "\nDOUBLE" << std::endl;
	iter(doubleArr, sizeof(doubleArr) / sizeof(double), print);
}
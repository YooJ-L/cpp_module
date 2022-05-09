#include "Conversion.hpp"
#include <cctype>
#include <cstdio>

int	removeWhiteSpaces(std::string &str)
{
	size_t	startIdx = 0;
	while (std::isspace(str[startIdx]) != 0)
		startIdx++;
	size_t	endIdx = str.length() - 1;
	while (std::isspace(str[endIdx]) != 0)
		endIdx--;
	if (startIdx > endIdx)
		return (1);
	str = str.substr(startIdx, endIdx - startIdx + 1);
	for (size_t i = 0; i < str.length(); i++) //중간에 공백 있을 경우 "1   23"
	{
		if (std::isspace(str[i]) != 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2 || *argv[1] == '\0')
	{
		std::cout << "ERROR: Just One Argument Is Allowed" << std::endl;
		return (0);
	}
	std::string input(argv[1]);
	if (removeWhiteSpaces(input))
	{
		std::cout << "ERROR: Wrong Argument" << std::endl;
		return (0);
	}
	try {
		Conversion	convert(input);
		convert.detectType();
	} catch (const std::exception &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}
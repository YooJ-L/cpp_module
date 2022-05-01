#include <iostream>

/*
참조 변수
&는 선언문에서랑 실행문에서 역할이 다름.
선언문에서는 참조자. 데이터형의 식별자 역할. string에 대한 참조
실행문에서는 주소 연산자.

std::string &stringREF = str;
stringREF 는 str의 참조자 (별명)
*/

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "===Address===" << std::endl;
	std::cout << "str: " << &str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "\n===String===" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return (0);
}
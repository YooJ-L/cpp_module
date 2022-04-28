#include "contact.hpp"

#include <iomanip> //setfill(), setw()
/*
setw(n) => 출력 시 길이를 n으로 지정
setfill(c) => 비어있는 공간을 c로 채움
	setfill은 한번 적용하면 계속 적용됨.
*/

std::string	Truncate(std::string str, size_t size)
{
	if (str.length() > size)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void	Contact::SetFirstName(std::string str) {
	_firstname = str;
}

void	Contact::SetLastName(std::string str) {
	_lastname = str;
}
void	Contact::SetNickname(std::string str) {
	_nickname = str;
}
void	Contact::SetPhoneNumber(std::string str) {
	_phonenumber = str;
}
void	Contact::SetDarkestSecret(std::string str) {
	_darkestsecret = str;
}

void	Contact::PrintFirstName() {
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << Truncate(_firstname, 10);
}

void	Contact::PrintLastName() {
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << Truncate(_lastname, 10);
}

void	Contact::PrintNickname() {
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << Truncate(_nickname, 10);
}
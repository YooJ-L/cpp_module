#include "contact.hpp"

#include <iomanip>

std::string	Truncate(std::string str, size_t size)
{
	if (str.length() > size)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

std::string	Contact::GetFirstName() const {
	return _firstname;
}

std::string	Contact::GetLastName() const {
	return _lastname;
}

std::string	Contact::GetNickname() const {
	return _nickname;
}

std::string	Contact::GetPhoneNumber() const {
	return _phonenumber;
}

std::string	Contact::GetDarkestSecret() const {
	return _darkestsecret;
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
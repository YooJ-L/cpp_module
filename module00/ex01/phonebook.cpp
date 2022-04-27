#include "phonebook.hpp"
#include <iomanip>

using std::cout;

PhoneBook::PhoneBook()
	: _idx(0),
	 _Contact() {}

void	PhoneBook::DrawTableRow() {
  cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
}

void	PhoneBook::DrawTableTop() {
  cout << "┌──────────┬──────────┬──────────┬──────────┐\n"
       << "│     Index│First Name│ Last Name│  Nickname│\n"
       << "├──────────┼──────────┼──────────┼──────────┤\n";
}

void	PhoneBook::DrawTableBottom() {
  cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}


void	PhoneBook::DrawContactTable() {
	DrawTableTop();
	for (int i = 0; i < _idx; i++) {
    	cout << "│";
    	cout << std::setfill(' ') << std::setw(10);
    	cout << i + 1;
    	cout << "│";
    	_Contact[i].PrintFirstName();
    	cout << "│";
    	_Contact[i].PrintLastName();
    	cout << "│";
    	_Contact[i].PrintNickname();
    	cout << "│";
    	cout << std::endl;
    	if (i < _idx - 1)
    	  DrawTableRow();
    	else
    	  DrawTableBottom();
  }
}

int		PhoneBook::InputSearchingIdx() {
	int	idx;
	cout << "\nSelect the Index: ";
	std::cin >> idx;
	if (std::cin.get() != '\n' || std::cin.fail())
	{
		std::cout << std::cin.fail() << std::endl;
		std::cin.clear(); //FAILBIT 꺼주는거
		std::cout << std::cin.fail() << std::endl;
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		return (-1);
	}
	cout << std::endl;
	return (idx);
}

void	PhoneBook::PrintContact(const int idx) {
	cout << "First Name: " << _Contact[idx].GetFirstName() << std::endl;
	cout << "Last Name: " << _Contact[idx].GetLastName() << std::endl;
	cout << "Nickname: " << _Contact[idx].GetNickname() << std::endl;
	cout << "Phone Number: " << _Contact[idx].GetPhoneNumber() << std::endl;
	cout << "Darkest Secret: " << _Contact[idx].GetDarkestSecret() << std::endl << std::endl;
}

void	PhoneBook::AddContact() {
	if (_idx == 8) {
		for (int i = 1; i < 8; i++) {
			_Contact[i - 1].SetFirstName(_Contact[i].GetFirstName());
			_Contact[i - 1].SetLastName(_Contact[i].GetLastName());
			_Contact[i - 1].SetNickname(_Contact[i].GetNickname());
			_Contact[i - 1].SetPhoneNumber(_Contact[i].GetPhoneNumber());
			_Contact[i - 1].SetDarkestSecret(_Contact[i].GetDarkestSecret());
		}
		_idx -= 1;
	}
	cout << std::endl;
	cout << "First Name: ";
	_Contact[_idx].SetFirstName(InputCmd());
	cout << "Last Name: ";
	_Contact[_idx].SetLastName(InputCmd());
	cout << "Nickname: ";
	_Contact[_idx].SetNickname(InputCmd());
	cout << "Phone Number: ";
	_Contact[_idx].SetPhoneNumber(InputCmd());
	cout << "Darkest Secret: ";
	_Contact[_idx].SetDarkestSecret(InputCmd());
	cout << std::endl;
	_idx += 1;
}

void	PhoneBook::SearchContact() {
	int	index;

	if (_idx > 0) {
		DrawContactTable();
		index = InputSearchingIdx();
		if (index > 0 && index <= _idx) {
			--index;
			PrintContact(index);
		}
		else {
			cout << "Not Available Index" << std::endl << std::endl;
		}
	}
	else
		cout << "Nothing" << std::endl << std::endl;
}

// void	PrintCmd() {
// 	cout << "Enter a command (ADD or SEARCH or EXIT): ";
// }

std::string InputCmd() {
	std::string input;
	std::getline(std::cin >> std::ws, input); //값 들어오기 전에 space들 안받아옴
	if (std::cin.eof())
		exit(0);
	return (input);
}
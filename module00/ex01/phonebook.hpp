
#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "contact.hpp"
# include <iostream>

class PhoneBook {
	private:
		int		_idx;
		Contact	_Contact[8];
		void	DrawContactTable();
		void	DrawTableRow();
		void	DrawTableTop();
		void	DrawTableBottom();
		int		InputSearchingIdx();

	public:
		PhoneBook();
		void		AddContact();
		void		SearchContact();
		void		PrintContact(const int idx);
};

std::string InputCmd();

#endif

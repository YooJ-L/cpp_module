/*
1. command 입력 받기
2. 
*/


#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include <iostream>

class Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _secret;

	public:


	Contact(void);
	~Contact(void);
};

class PhoneBook {
	private:


	public:
		void PrintCmd(void);
		std::string InputCmd(void);

	
	PhoneBook(void);
	~PhoneBook(void);
};

#endif
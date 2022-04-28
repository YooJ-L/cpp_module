#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;

	public:
		std::string	GetFirstName() const { return _firstname; }
		std::string GetLastName() const { return _lastname; }
  		std::string GetNickname() const { return _nickname; }
  		std::string GetPhoneNumber() const { return _phonenumber; }
  		std::string GetDarkestSecret() const { return _darkestsecret; }
		void	SetFirstName(std::string str);
		void	SetLastName(std::string str);
		void	SetNickname(std::string str);
		void	SetPhoneNumber(std::string str);
		void	SetDarkestSecret(std::string str);
		void	PrintFirstName();
		void	PrintLastName();
		void	PrintNickname();
};

#endif
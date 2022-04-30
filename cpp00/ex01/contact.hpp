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
		std::string	GetFirstName() const;
		std::string GetLastName() const;
  		std::string GetNickname() const;
  		std::string GetPhoneNumber() const;
  		std::string GetDarkestSecret() const;
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
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int _bit;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		~Fixed();

		Fixed &operator=(Fixed const &obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
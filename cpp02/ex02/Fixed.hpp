#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_numValue;
		static const int _fractionalBit = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int intNum);
		Fixed(const float floatNum);
		~Fixed();

		Fixed	&operator =(Fixed const &obj);
		bool	operator >(const Fixed &obj);
		bool	operator <(const Fixed &obj);
		bool	operator >=(const Fixed &obj);
		bool	operator <=(const Fixed &obj);
		bool	operator ==(const Fixed &obj);
		bool	operator !=(const Fixed &obj);

		const Fixed	operator +(const Fixed &obj);
		const Fixed	operator -(const Fixed &obj);
		const Fixed	operator *(const Fixed &obj);
		const Fixed	operator /(const Fixed &obj);

		Fixed	&operator ++();
		Fixed	&operator --();

		const Fixed operator ++(int);
		const Fixed operator --(int);

		static Fixed &min(Fixed &a1, Fixed &a2);
		static Fixed &max(Fixed &a1, Fixed &a2);

		static const Fixed	&max(const Fixed &a1, const Fixed &a2);

		int		getRawBits() const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
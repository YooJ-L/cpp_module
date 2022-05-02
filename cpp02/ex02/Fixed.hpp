#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_numValue;
		static const int _fractionalBit = 8; //객체에 의존적이지 않다. 클래스를 대표한다.
	
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int intNum);
		Fixed(const float floatNum);
		~Fixed();

		Fixed	&operator =(const Fixed &obj);
		bool	operator >(const Fixed &obj) const;
		bool	operator <(const Fixed &obj) const;
		bool	operator >=(const Fixed &obj) const;
		bool	operator <=(const Fixed &obj) const;
		bool	operator ==(const Fixed &obj) const;
		bool	operator !=(const Fixed &obj) const;

		const Fixed	operator +(const Fixed &obj) const;
		const Fixed	operator -(const Fixed &obj) const;
		const Fixed	operator *(const Fixed &obj) const;
		const Fixed	operator /(const Fixed &obj) const;

		//전위연산자
		Fixed	&operator ++();
		Fixed	&operator --();

		//후위연산자
		const Fixed operator ++(int);
		const Fixed operator --(int);

		static Fixed &min(Fixed &a1, Fixed &a2);
		static Fixed &max(Fixed &a1, Fixed &a2);

		static const Fixed &min(const Fixed& a1, const Fixed& a2);
		static const Fixed &max(const Fixed& a1, const Fixed& a2);

		int		getRawBits() const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_numValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) //복사 생성자
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed; //연산자 오버로딩
}

Fixed::Fixed(const int intNum) //fixed-point value로 바꾸기
{
	std::cout << "Int constructor called" << std::endl;
	_numValue = intNum * 256;
}

Fixed::Fixed(const float floatNum) //fixed-point value로 바꾸기
{
	std::cout << "Float constructor called" << std::endl;
	_numValue = roundf(floatNum * 256);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operation called" << std::endl;
	_numValue = obj.getRawBits();
	return (*this);
}

//비교연산자

bool	Fixed::operator >(const Fixed &obj) const
{
	return (this->_numValue > obj._numValue);
}

bool	Fixed::operator <(const Fixed &obj) const
{
	return (this->_numValue < obj._numValue);
}

bool	Fixed::operator >=(const Fixed &obj) const
{
	return (this->_numValue >= obj._numValue);
}

bool	Fixed::operator <=(const Fixed &obj) const
{
	return (this->_numValue <= obj._numValue);
}

bool	Fixed::operator ==(const Fixed &obj) const
{
	return (this->_numValue == obj._numValue);
}

bool	Fixed::operator !=(const Fixed &obj) const
{
	return (this->_numValue != obj._numValue);
}

//사칙연산자
const Fixed	Fixed::operator +(const Fixed &obj) const
{
	Fixed result(*this);

	result._numValue += obj._numValue;
	return result;
}

const Fixed	Fixed::operator -(const Fixed &obj) const
{
	Fixed result(*this);

	result._numValue -= obj._numValue;
	return result;
}
const Fixed	Fixed::operator *(const Fixed &obj) const
{
	Fixed result(*this);

	result._numValue = (result._numValue * obj._numValue) / 256;
	return result;
}

const Fixed	Fixed::operator /(const Fixed &obj) const
{
	Fixed result(*this);
	
	result._numValue = (result._numValue * 256) / obj._numValue;
	return result;
}

//증감연산자

Fixed &Fixed::operator ++()
{
	++_numValue;
	return (*this);
}

Fixed &Fixed::operator --()
{
	--_numValue;
	return (*this);
}

const Fixed Fixed::operator ++(int)
{
	Fixed temp = *this;
	_numValue++;
	return (temp);
}

const Fixed Fixed::operator --(int)
{
	Fixed temp = *this;
	_numValue--;
	return (temp);
}

Fixed &Fixed::min(Fixed& a1, Fixed& a2)
{
	return (a1 < a2 ? a1 : a2);
}
const Fixed &Fixed::min(const Fixed& a1, const Fixed& a2)
{
	return (a1 < a2 ? a1 : a2);
}
Fixed &Fixed::max(Fixed& a1, Fixed& a2)
{
	return (a1 > a2 ? a1 : a2);
}
const Fixed &Fixed::max(const Fixed& a1, const Fixed& a2)
{
	return (a1 > a2 ? a1 : a2);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_numValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_numValue = raw;
}

float	Fixed::toFloat() const //fixed-point value => floating-point value
{
	return (static_cast<float>(_numValue / 256.0f));
}

int		Fixed::toInt() const //fixed-point value => integer value
{
	return (_numValue / 256);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}
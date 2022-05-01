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

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

bool	Fixed::operator >(const Fixed &obj)
{
	return (this->_numValue > obj._numValue);
}

bool	Fixed::operator <(const Fixed &obj)
{
	return (this->_numValue < obj._numValue);
}

bool	Fixed::operator >=(const Fixed &obj)
{
	return (this->_numValue >= obj._numValue);
}

bool	Fixed::operator <=(const Fixed &obj)
{
	return (this->_numValue <= obj._numValue);
}

bool	Fixed::operator ==(const Fixed &obj)
{
	return (this->_numValue == obj._numValue);
}

bool	Fixed::operator !=(const Fixed &obj)
{
	return (this->_numValue != obj._numValue);
}

Fixed	&Fixed::operator +(const Fixed &obj)
{
	Fixed	
	return (this->_numValue + obj._numValue);
}

int		Fixed::operator -(const Fixed)

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
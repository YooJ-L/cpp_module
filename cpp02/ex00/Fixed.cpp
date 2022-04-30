#include "Fixed.hpp"

const int Fixed::_bit = 8;

Fixed::Fixed()
{
	this->_numValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) //복사 생성자
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj; //연산자 오버로딩
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

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_numValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_numValue = raw;
}

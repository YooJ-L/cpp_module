#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const std::string type)
: _type(type)
{
	std::cout << "Animal Conversion constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
: _type(other._type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator =(const Animal &other)
{
	_type = other.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

const std::string& Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "[ Animal ]..." << std::endl;
}
#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
: WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator =(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	_type = other.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "[ WrongCat ] meow meow" << std::endl;
}
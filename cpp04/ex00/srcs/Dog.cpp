#include "../includes/Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
: Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator =(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	_type = other.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "[ Dog ] woof woof" << std::endl;
}
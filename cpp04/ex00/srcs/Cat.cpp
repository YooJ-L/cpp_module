#include "../includes/Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
}
// 이거 왜 없음
// Cat::Cat(const std::string type)
// : _type(type)
// {
// 	std::cout << "Cat Conversion constructor called" << std::endl;
// }

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator =(const Cat &other)
{
	_type = other.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "[ Cat ] meow meow" << std::endl;
}
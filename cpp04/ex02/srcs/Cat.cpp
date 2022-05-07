#include "../includes/Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	_brainPTR = new Brain;
}

Cat::Cat(const Cat &other)
: Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	_brainPTR = new Brain();
	*this = other;
}

Cat& Cat::operator =(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	_type = other.getType();
	*(_brainPTR) = *(other._brainPTR);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _brainPTR;
}

void	Cat::makeSound() const
{
	std::cout << "[ Cat ] meow meow" << std::endl;
}

void	Cat::selectIdea(size_t idx) const
{
	std::cout << this->getType() << "'s _ideas[" << idx << "] "
				<< _brainPTR->getIdea(idx) << std::endl;
}

void	Cat::changeIdea(const size_t idx, const std::string &idea)
{
	_brainPTR->setIdea(idea, idx);
}
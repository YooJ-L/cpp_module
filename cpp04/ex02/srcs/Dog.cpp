#include "../includes/Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	_brainPTR = new Brain("Dog's default idea");
}

Dog::Dog(const Dog &other)
:Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	_brainPTR = new Brain();
	*this = other;
}

Dog& Dog::operator =(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	_type = other.getType();
	*(_brainPTR) = *(other._brainPTR);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete _brainPTR;
}

void	Dog::makeSound() const
{
	std::cout << "[ Dog ] woof woof" << std::endl;
}

void	Dog::selectIdea(size_t idx) const
{
	std::cout << "[ " << this->getType() << "'s _ideas[" << idx << "] "
				<< _brainPTR->getIdea(idx) << std::endl;
}

void	Dog::changeIdea(const std::string &idea, const size_t idx)
{
	_brainPTR->setIdea(idea, idx);
}
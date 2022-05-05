#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "\0";
}

Brain::Brain(const std::string idea)
{
	std::cout << "Brain Conversion constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		setIdea(idea, i);
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator =(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = other.getIdea(i);
	}	
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::setIdea(const std::string &idea, const size_t idx)
{
	_ideas[idx] = idea;
}

const std::string& Brain::getIdea(const size_t idx) const
{
	return (this->_ideas[idx]);
}
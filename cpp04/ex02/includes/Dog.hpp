#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brainPTR;

	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator =(const Dog &other);
		virtual ~Dog();

		void	makeSound() const;
		void	selectIdea(size_t idx) const;
		void	changeIdea(const std::string &idea, const size_t idx);
};

#endif
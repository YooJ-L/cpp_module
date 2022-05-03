#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator =(const Cat &other);
		~Cat();

		void	makeSound() const;
};

#endif
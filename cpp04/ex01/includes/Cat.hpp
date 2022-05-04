#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brainPTR;

	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator =(const Cat &other);
		virtual ~Cat();

		void	makeSound() const;
		void	selectIdea(size_t idx) const;
		void	changeIdea(const size_t idx, const std::string &idea);
};

#endif
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
//<string> 인클루드 하는 이유?
class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator =(const WrongAnimal &other);
		~WrongAnimal();

		const std::string& getType() const;
		void	makeSound() const;
};

#endif
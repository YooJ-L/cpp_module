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
		WrongAnimal(const std::string type); //const 쓰는 이유?
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator =(const WrongAnimal &other);
		~WrongAnimal();

		const std::string& getType() const; //앞에 쓰는 Const 뒤에 쓰는 getType 앞에 쓰는 것 차이?

		void	makeSound() const;
};

#endif
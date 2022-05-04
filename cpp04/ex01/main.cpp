#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"

int main()
{
	//subject
	{
		std::cout << "=====subject=====" << std::endl;
		const Animal* meta = new Animal();
		
		std::cout << std::endl;
		const Animal* j = new Dog();
		
		std::cout << std::endl;
		const Animal* i = new Cat();
		
		std::cout << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;
		delete meta;
		delete j;//should not create a leak
		delete i;
		system("leaks animalbrain");
	}

	{
		std::cout << "\n\n================" << std::endl;
		Animal *zoo[10];
		
		std::cout << std::endl;
		WrongAnimal *weird[10];
		
		std::cout << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "\nzoo[" << i << "]" << std::endl;
			zoo[i] = new Dog();
			std::cout << "\nweird[" << i << "]" << std::endl;
			weird[i] = new WrongCat();
		}
		for (int i = 5; i < 10; i++)
		{
			std::cout << "\nzoo[" << i << "]" << std::endl;
			zoo[i] = new Cat();
			std::cout << "\nweird[" << i << "]" << std::endl;
			weird[i] = new WrongCat();
		}
		for (int i = 0; i < 10; i++)
		{
			zoo[i]->makeSound();
			weird[i]->makeSound();
		}
		for (int i = 0; i < 10; i++)
		{
			delete zoo[i];
			delete weird[i];
		}
		system("leaks animalbrain");
	}

	//얕은 복사 테스트
	std::cout << "\n\n=====Shallow Copy=====" << std::endl;
	Dog original;
	Dog copy;

	copy = original;
	std::cout << "------ original's ideas-----" << std::endl;
	original.selectIdea(0);
	std::cout << "------ copy's ideas-----" << std::endl;
	copy.selectIdea(0);

	copy.changeIdea("HIHIHI", 0);

	std::cout << "------ original's ideas-----" << std::endl;
	original.selectIdea(0);
	std::cout << "------ copy's ideas-----" << std::endl;
	copy.selectIdea(0);

	//깊은 복사
	std::cout << "\n\n=====Deep Copy======" << std::endl;
	Dog original2;
	Dog copy2(original);

	std::cout << "------ original's ideas-----" << std::endl;
	original2.selectIdea(0);
	std::cout << "------ copy's ideas-----" << std::endl;
	copy2.selectIdea(0);

	copy2.changeIdea("HIHIHI", 0);

	std::cout << "------ original's ideas-----" << std::endl;
	original2.selectIdea(0);
	std::cout << "------ copy's ideas-----" << std::endl;
	copy2.selectIdea(0);
	system("leaks animalbrain");
	return 0;
}

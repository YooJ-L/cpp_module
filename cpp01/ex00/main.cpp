#include "Zombie.hpp"

/*
newZombie함수는 zombie클래스의 인스턴스를 생성하고 현재 인스턴스가 선언된 공간 외부에서도 사용 가능하게 반환하라는 것
=> 스택에 할당하면 자동으로 소멸되니까 힙에 메모리 할당

스택의 경우 선언했던 함수를 벗어나면 자동으로 소멸.

randomChump는 좀비 클래스 인스턴스 생성, announce 함수 호출 끝. => 함수를 벗어나면 자동으로 소멸.
*/
int	main(void)
{
	std::cout << "===Heap===" << std::endl;
	Zombie *zombieHeap1;
	Zombie *zombieHeap2;

	zombieHeap1 = newZombie("zombieHeap1");
	zombieHeap2 = newZombie("zombieHeap2");
	zombieHeap1->announce();
	zombieHeap2->announce();

	std::cout << "\n===Stack===" << std::endl;
	Zombie zombieStack1("zombieStack1");
	Zombie zombieStack2("zombieStack2");

	zombieStack1.announce();
	zombieStack2.announce();

	std::cout << "\n===RandomChump===" << std::endl;
	randomChump("RandomZombie1");
	randomChump("RandomZombie2");
	
	std::cout << std::endl << std::endl;

	delete zombieHeap1;
	delete zombieHeap2;
	return (0);
}
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "\n===== Subject =====" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack Top  : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "mstack Size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "mstack begin : " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "mstack end   : " << *ite << std::endl;
	++it;
	std::cout << "++it         : " << *it << std::endl;
	--it;
	std::cout << "--it         : " << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "stack Top: " << s.top() << std::endl;

	std::cout << "\n===== Reverse Test =====" << std::endl;
	MutantStack<std::string> rTest;
	rTest.push("AAA");
	rTest.push("BBB");
	rTest.push("CCC");
	rTest.push("DDD");
	rTest.push("EEE");
	rTest.push("FFF");
	rTest.push("GGG");
	MutantStack<std::string>::reverse_iterator it1 = rTest.rbegin();
	MutantStack<std::string>::reverse_iterator it2 = rTest.rend();
	for (; it1 != it2; it1++)
		std::cout << *it1 << std::endl;

	std::cout << "\n===== Compare with List =====" << std::endl;
	std::list<int> li;
	MutantStack<int> ms;
	for (int i = 0; i < 10; i++)
	{
		li.push_back(i);
		ms.push(i);
	}
	std::list<int>::iterator li_it = li.begin();
	std::list<int>::iterator li_ite = li.end();
	MutantStack<int>::iterator ms_it = ms.begin();
	MutantStack<int>::iterator ms_ite = ms.end();
	std::cout << "li begin: " << *li_it << ", li end: " << *(--li_ite) << std::endl;
	std::cout << "ms begin: " << *ms_it << ", ms end: " << *(--ms_ite) << std::endl;
	std::cout << "\nlist ++ : ";
	for (; li_it != li_ite; li_it++)
		std::cout << *li_it << "  ";
	std::cout << "\nMutantStack ++ : ";
	for (; ms_it != ms_ite; ms_it++)
		std::cout << *ms_it << "  ";

	// for (; li_it != li_ite && ms_it != ms_ite; li_it++, ms_it++) {
	// 	std::cout << *li_it << " ::: " << *ms_it;
	// 	std::cout << std::endl;
	// }
	return 0;
}
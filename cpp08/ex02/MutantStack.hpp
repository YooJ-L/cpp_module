#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack()
		: std::stack<T, C>() {}

		~MutantStack() {}

		MutantStack(const MutantStack& other)
		{
			if (this != &other)
				*this = other;
			return (*this);
		}

		typedef typename
			std::stack<T, C>::container_type::iterator					iterator;
		typedef typename
			std::stack<T, C>::container_type::const_iterator			const_iterator;
		typedef typename
			std::stack<T, C>::container_type::reverse_iterator			reverse_iterator;
		typedef typename
			std::stack<T, C>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }
};




#endif
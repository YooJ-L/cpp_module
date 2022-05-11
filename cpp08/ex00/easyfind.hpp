#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator pos;
	pos = std::find(container.begin(), container.end(), value);
	if (pos == container.end()) {
		throw std::runtime_error("Cannot find value");
	}
	return pos;
};

#endif

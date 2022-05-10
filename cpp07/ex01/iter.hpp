#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	print(const T& arg)
{
	std::cout << arg << std::endl;
}

template <typename T>
void	iter(T* array, std::size_t len, void (*fPtr)(const T&))
{
	if (!array || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
		(*fPtr)(array[i]);
}

#endif
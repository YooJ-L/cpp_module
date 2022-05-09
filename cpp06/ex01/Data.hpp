#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct	Data
{
	std::string str;
	char		character;
	int			integer;
};

uintptr_t	serialize(Data *ptr);
Data*		deserialize(uintptr_t raw);

#endif
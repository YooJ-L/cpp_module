#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	typedef struct	Harl_s {
		std::string level;
		void		(Harl::*function)();
	} Harl_t;

	private:
		Harl_t	_levels_fn[4];

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
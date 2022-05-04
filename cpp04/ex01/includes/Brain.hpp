#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const std::string idea);
		Brain(const Brain &other);
		Brain& operator =(const Brain &other);
		~Brain();

		void				setIdea(const std::string &idea, const size_t idx);
		const std::string&	getIdea(const size_t idx) const;
};

#endif
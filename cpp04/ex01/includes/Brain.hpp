#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(std::string idea);
		Brain(const Brain &other);
		Brain& operator =(const Brain &other);
		~Brain();

		// void	openIdeas();
		void				setIdeas(const std::string &idea);
		const std::string&	getIdea(const size_t idx) const;
};

#endif
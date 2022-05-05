#ifdef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	private:
		const std::string _target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(cosnt PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator =(const PresidentialPardonForm &other);

		virtual const std::string&	getTarget() const;
		
		virtual void	execute(const Bureaucrat &executor) const;
};

#endif
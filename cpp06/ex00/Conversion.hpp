#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>
# include <string> //replace
# include <cfloat>
# include <iomanip> //std::setprecision

class Conversion
{	
	public:
		enum Type {
			CHAR_,
			INT_,
			FLOAT_,
			DOUBLE_
		};

		Conversion();
		Conversion(const std::string &input);
		Conversion(const Conversion &other);
		~Conversion();
		Conversion& operator =(const Conversion &other);

		bool	checkFlags();

		void	detectType();
		bool	detectChar();
		bool	detectInt();
		bool	detectFloat();
		bool	detectDouble();
		bool	detectInfNan();

		void	convert() const;

		void	convertChar();
		void	convertInt();
		void	convertFloat();
		void	convertDouble();
		void	convertInfNan() const;

		const std::string& getInput() const;

	private:
		const std::string	_input;
		void	(Conversion::*_pF[5])() const;

		Type	_type;

		int		_fFlag;
		int		_dotFlag;
		int		_InfNanFlag;

		char	_c;
		int		_i;
		float	_f;
		double	_d;

		class InvalidInputException : public std::exception {
			public:
				const char *what() const throw();
		};


};


#endif
#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <iomanip> //std::setprecision

class Conversion
{	
	public:
		enum Type {
			CHAR_,
			INT_,
			FLOAT_,
			DOUBLE_,
			INIT_
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

		void	convertChar() const;
		void	convertInt() const;
		void	convertFloat() const;
		void	convertDouble() const;
		void	convertInfNan() const;

		const std::string& getInput() const;
		const Type& getType() const;

	private:
		std::string	_input;
		void	(Conversion::*_pF[5])() const;

		Type	_type;

		int		_fFlag;
		int		_dotFlag;
		int		_InfNanFlag;

		char	_c;
		int		_i;
		float	_f;
		double	_d;

		int		_inputSize;

		class InvalidInputException : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
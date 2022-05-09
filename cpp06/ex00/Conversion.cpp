#include "Conversion.hpp"

Conversion::Conversion()
: _input("")
{
	_type = -1;
	_fFlag = 0;
	_dotFlag = 0;
	_InfNanFlag = 0;
	_c = 0;
	_i = 0;
	_f = 0;
	_d = 0;
	_pF[0] = &Conversion::convertChar;
	_pF[1] = &Conversion::convertInt;
	_pF[2] = &Conversion::convertFloat;
	_pF[3] = &Conversion::convertDouble;
}

Conversion::Conversion(const std::string &input)
: _input(input)
{
	_pF[0] = &Conversion::convertChar;
	_pF[1] = &Conversion::convertInt;
	_pF[2] = &Conversion::convertFloat;
	_pF[3] = &Conversion::convertDouble;
	_type = -1;
	_fFlag = 0;
	_dotFlag = 0;
	_InfNanFlag = 0;
	_c = 0;
	_i = 0;
	_f = 0;
	_d = 0;
}

Conversion::Conversion(const Conversion &other)
: _input(other->getInput())
{
	*this = other;
}

Conversion::~Conversion() {}

Conversion& Conversion::operator =(const Conversion &other)
{
	_pF[0] = other._pF[0];
	_pF[1] = other._pF[1];
	_pF[2] = other._pF[2];
	_pF[3] = other._pF[3];
	_pF[4] = other._pF[4];
	_type = other._type;
	_c = other._c;
	_i = other._i;
	_f = other._f;
	_d = other._d;
	_fFlag = other._fFlag;
	_dotFlag = other._dotFlag;
	_InfNanFlag = other._InfNanFlag;
	return (*this);
}

void	Conversion::detectType()
{
	if (detectChar() || detectInfNan())
		return ;
	else if (checkFlags())
	{
		if (detectFloat() || detectDouble() || detectInt()))
			return ;
	}
	else
		throw InvalidInputException();
}

bool	Conversion::detectChar()
{
	if ((_input.length() == 1 && !std::isdigit(_input[0]) && _input[0] >= 32 && _input[0] <= 126))
	{
		_c = _input[0];
		_type = CHAR_;
		return true;
	}
	else if (_input.length() == 3 && _input[0] == '\'' && _input[2] == '\'' && !std::isdigit(_input[1] && _input[1] >= 32 && _input[1] <= 126)
	{
		_c = _input[1];
		_type = CHAR_;
		return true;
	}
	else
		return false;
}

bool	Conversion::detectInfNan()
{
	if (_input == "nanf" || _input == "inff" || _input == "+inff" || _input == "-inff") //+nan -nan?
	{
		_type = FLOAT_;
		_input = _input.replace(_input.length() - 1, 1, "");
	}
	else if (_input == "nan" || _input == "inf" || _input == "+inf" || _input == "-inf")
		_type = DOUBLE_;
	else
		return false;
	_InfNanFlag = 1;
	return true;
}

bool	Conversion::checkFlags()
{
	for (int i = 0; i < _input.length(); i++)
	{
		if (_input[i] == '.')
			_dotFlag += 1;
		else if (_input[i] == 'f')
			_fFlag += 1;
		else if (std::isdigit(_input[i]))
			continue ;
		else
			return false;
	}
	return true;
}

bool	Conversion::detectFloat()
{
	unsigned log	fIdx = _input.find('f');
	if (_fFlag != 1 || _dotFlag != 1 || fIdx != _input.length() - 1)
		return false;
	_type = FLOAT_;
	std::stringstream iss(_input.replace(_input.length() - 1, 1, ""));
	float temp = 0.0f;
	iss >> temp;
	if (iss.fail())
		throw InvalidInputException();
	_f = temp;
	return true;
}

bool	Conversion::detectDouble()
{
	if (_fFlag != 0 || _dotFlag != 0)
		return false;
	_type = DOUBLE_;
	std::stringstream iss(_input);
	double temp = 0.0;
	iss >> temp;
	if (iss.fail())
		throw InvalidInputException();
	_d = temp;
	return true;
}

bool	Conversion::detectInt()
{
	if (_fFlag != 0 || _dotFlag != 0)
		return false;
	_type = INT_;
	std::stringstream iss(_input);
	int	temp = 0;;
	iss >> temp;
	if (iss.fail())
		throw InvalidInputException();
	_i = temp;
	return true;
}

void	Conversion::convert() const
{
	if (_InfNanFlag == 1)
	{
		convertInfNan();
		return ;
	}
	else
		(this->*_pF[_type])();
}

void	Conversion::convertChar()
{
	std::cout << "char: \'" << _c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(_c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_c) << std::endl;
}

void	Conversion::convertInt()
{
	//char
	std::cout << "char: ";
	if (_i < -128 || _i > 127)
		std::cout << "impossible" << std::endl;
	else if (_i < 32 || _i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(_i) << "\'" << std::endl;
	//int
	std::cout << "int: " << _i << std::endl;
	std::cout << "float: " << static_cast<float>(_i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_i) << std::endl;
}

void	Conversion::convertFloat()
{
	std::cout << "char: ";
	if (_f < -128 || _f > 127)
		std::cout << "impossible" << std::endl;
	else if (_f < 32 || _f > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(_f) << "\'" << std::endl;
	std::cout << "int: ";
	if (_f > INT_MAX || _f < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(_f) << std::endl;
	std::cout << "float: " << _f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_f) << std::endl;
}

void	Conversion::convertDouble()
{
	std::cout << "char: ";
	if (_d < -128 || _d > 127)
		std::cout << "impossible" << std::endl;
	else if (_f < 32 || _f > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(_d) << "\'" << std::endl;
	std::cout << "int: ";
	if (_d > INT_MAX || _d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(_d) << std::endl;
	std::cout << "float: ";
	if (_d > FLT_MAX || _d < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(_d) << "f" << std::endl;
	std::cout << "double: " << _d << std::endl;
}

void	Conversion::convertInfNan() const
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << _input << "f" << std::endl;
	std::cout << "double: " << _input << std::endl;
}

const std::string& Conversion::getInput() const
{
	return _input;
}

const char *Conversion::InvalidInputException::what() const throw()
{
	return ("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible");
}
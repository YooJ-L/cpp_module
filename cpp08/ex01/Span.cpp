#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N)
: _maxSize(N) {}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
	_maxSize = other._maxSize;
	_data = other._data;
	return *this;
}

void	Span::addNumber(int value)
{
	if (_data.size() >= _maxSize)
		throw std::out_of_range("!!No Space!! Cannot Add Number");
	_data.insert(value);
}

unsigned int	Span::shortestSpan()
{
	if (_data.size() < 2)
		throw std::logic_error("Not enough element to get a span");
	std::multiset<int>::iterator cur = _data.begin();
	int	before = *cur;
	++cur;
	int	min = *cur - before;
	while (cur != _data.end())
	{
		if (min > (*cur - before))
			min = *cur - before;
		before = *cur;
		++cur;
	}
	return (min);
}

unsigned int	Span::longestSpan()
{
	if (_data.size() < 2)
		throw std::logic_error("Not enough element to get a span");
	return (*(--(_data.end())) - *(_data.begin()));
}
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <exception>

class Span
{
	private:
		unsigned int	_maxSize;
		std::multiset<int>	_data;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();
		Span& operator=(const Span& other);

		void	addNumber(int value);

		template<typename Iter>
		void	addNumber(Iter begin, Iter end);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

template <typename Iter>
void	Span::addNumber(Iter begin, Iter end)
{
	for (; begin != end; begin++)
	{
		addNumber(*begin);
	}
}

#endif

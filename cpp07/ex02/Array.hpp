#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array& operator=(const Array& other);
		T& operator[](long index) const;
		
		unsigned int size() const;
};

template<typename T>
Array<T>::Array()
: _arr(new T[0]), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n)
: _arr(new T[n]), _size(n) {}

template<typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template<typename T>
Array<T>::Array(const Array& other)
{
	_arr = new T[0];
	*this = other;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;
	delete[] _arr;
	_size = other._size;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
	return (*this);
}

template<typename T>
T& Array<T>::operator[](long index) const
{
	if (index < 0 || index >= _size)
		throw std::out_of_range("Out of Range");
	return _arr[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
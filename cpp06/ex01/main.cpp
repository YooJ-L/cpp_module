#include "Data.hpp"
#include <cstdint>

int	main(void)
{
	Data	data = {"Hello", 'H', 123};
	uintptr_t	raw;
	Data 		*dataPtr;

	std::cout << "===== Original =====" << std::endl;
	std::cout << data.str << std::endl;
	std::cout << data.character << std::endl;
	std::cout << data.integer << std::endl;
	std::cout << &data << std::endl;

	std::cout << "===== Serialize & Deserialize =====" << std::endl;
	raw = serialize(&data);
	dataPtr = deserialize(raw);

	std::cout << raw << std::endl;

	std::cout << "===== After =====" << std::endl;
	std::cout << dataPtr->str << std::endl;
	std::cout << dataPtr->character << std::endl;
	std::cout << dataPtr->integer << std::endl;
}
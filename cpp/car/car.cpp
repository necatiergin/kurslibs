#include "car.h"

std::ostream& operator<<(std::ostream& os, const Car& other)
{
	other.print(os);
	return os;
}

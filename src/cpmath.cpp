#include "cpmath.h"
#include <cmath>
#include <stdexcept>

namespace cp { namespace math {

int get_num_digits(int num)
{
	return static_cast<int>(
		floor(log(std::abs(num)) / log(10))) + 1;
}

int get_factorial(int num)
{
	if(num < 0)
		throw std::invalid_argument("num");

	int factorial = 1;
	for(int i = num; i > 1; --i)
		factorial *= i;

	return factorial;
}

} } // end namespaces

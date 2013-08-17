#include "cpprime.h"
#include <vector>
#include <iterator>
#include <math.h>

namespace cp { namespace math {

int get_gcf(int n1, int n2)
{
	int temp;
	while(n2 != 0)
	{
		temp = n2;
		n2 = n1 % temp;
		n1 = temp;
	}
	return n1;
}

} } // end namespaces

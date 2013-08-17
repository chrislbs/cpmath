#ifndef _cp_prime_h_
#define _cp_prime_h_

#include <vector>
#include <iterator>
#include <math.h>

namespace cp { namespace math {

template<typename back_inserter>
void generate_primes(int upper, back_inserter iter)
{
	if(upper < 2)
		return;

	std::vector<bool> isprime(upper, true);
	for(size_t i = 2; i <= isprime.size(); ++i)
	{
		if(!isprime[i - 1])
			continue;

		*iter = i;

		++iter;

		for(size_t j = i + i; j <= isprime.size(); j += i)
			isprime[j - 1] = false;
	}
}

template<typename back_inserter>
void get_prime_factors(int num, back_inserter iter)
{
	int upper = static_cast<int>(sqrt(num));
	std::vector<int> primes;

	generate_primes(upper, std::back_inserter(primes));

	std::vector<int>::iterator pi = primes.begin();
	while(pi != primes.end())
	{
		if(num % *pi == 0)
		{
			num /= *pi;
			*iter = *pi;
			++iter;
		}
		else
			++pi;
	}
	if(num != 1)
	{
		*iter = num;
		++iter;
	}
}

int get_gcf(int n1, int n2);

} }

#endif

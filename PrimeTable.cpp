#include "PrimeTable.h"

namespace PrimeTable
{
	const unsigned int primeTable[9] = { 2,3,5,7,11,13,17,23,29 };

	const unsigned int& GetPrimeNumber(unsigned int& index)
	{
		return primeTable[index];
	}

	const unsigned int& GetPrimeNumber(const unsigned int& index)
	{
		return primeTable[index];
	}
}


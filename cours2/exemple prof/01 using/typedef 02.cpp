#include <iostream>

using namespace std;

/*

	Quelques alias prédéfinis avec "typedef" dans votre environnement de développement Microsoft

	Il suffit d'inclure une librairie standard comme <iostream> pour y avoir accès

*/

int main()
{
	// définis dans <stdint.h>

	int8_t	v1 = 0;		// typedef signed char	int8_t
	int16_t v2 = 0;		// typedef short		int16_t
	int32_t v3 = 0;		// typedef int			int32_t
	int64_t v4 = 0;		// typedef long long	int64_t

	uint8_t	 v5 = 0;	// typedef unsigned char		uint8_t
	uint16_t v6 = 0;	// typedef unsigned short		uint16_t
	uint32_t v7 = 0;	// typedef unsigned int			uint32_t
	uint64_t v8 = 0;	// typedef unsigned long long	uint64_t


	// définis dans <vcruntime.h>

	size_t s = 0;		// (en x86) typedef unsigned int		size_t
						// (en x64) typedef unsigned long long	size_t


	// définis dans <corecrt.h>

	time_t t = 0;		// typedef long long	time_t
}
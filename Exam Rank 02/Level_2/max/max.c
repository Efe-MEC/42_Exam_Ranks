#include <limits.h>

int	max(int* tab, unsigned int len)
{
	int count = 0;
	int result = INT_MIN;
	int i = 0;
	if (len > 0)
	{
		while (count < len)
		{
			if (tab[count] > result)
				result = tab[count];
			count++;
		}
		return (result);
	}
	return (0);
}

#include <stdlib.h>

static int	ft_absolute_value(int number)
{
	if (number < 0x0)
		return (-number);
	return (number);
}

int	*ft_range(int start, int end)
{
	int	size;
	int	step;
	int	*tab;
	int	index;

	index = 0;
	step = 0;
	size = ft_absolute_value(start - end);
	tab = (int *)malloc(sizeof(int) * size + 1);
	if (!tab)
		return (EXIT_FAILURE);
	if (start < end)
		step = 1;
	else
		step = -1;
	while (index < size)
	{
		tab[index] = start;
		start = start + step;
		index++;
	}
	return (tab);
}

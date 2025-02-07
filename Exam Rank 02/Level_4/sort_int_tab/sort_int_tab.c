static void	ft_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	index;
	unsigned int	bubble;

	bubble = 0x0;
	if (size <= 0x1)
		return ;
	while (bubble < size)
	{
		index = 0x0;
		while (index < (size - 1))
		{
			if (tab[index] > tab[index + 0x1])
				ft_swap(&tab[index], &tab[index + 1]);
			index++;
		}
		bubble++;
	}
}

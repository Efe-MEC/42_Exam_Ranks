#include <stdlib.h>

static int	ft_length(long number)
{
	int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number *= -1;
		length++;
	}
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

static void	ft_fill_string(char *string, long number, int len)
{
	string[len] = '\0';
	if (number == 0)
		string[0] = '0';
	else
	{
		if (number < 0)
		{
			string[0] = '-';
			number = -number;
		}
		while (number)
		{
			string[--len] = (number % 10) + '0';
			number /= 10;
		}
	}
}

char *ft_itoa(int nbr)
{
	int		length;
	long	number;
	char	*string;

	number = nbr;
	length = ft_length(number);
	string = ((char *)malloc(length + 1));
	if (!string)
		return (NULL);
	ft_fill_string(string, number, length);
	return (string);
}

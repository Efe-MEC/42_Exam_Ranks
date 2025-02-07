#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *accept)
{
	size_t i;
	size_t j;
	int check;

	i = 0;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return(i);
}
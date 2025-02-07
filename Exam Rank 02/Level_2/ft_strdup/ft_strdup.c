#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i;
	int j;
	char *dest;

	i = 0;
	while (src[i])
		i++;
	dest =  (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	while(src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
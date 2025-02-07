char    *ft_strrev(char *str)
{
	int i;
	int j;
	char temp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (j < i - 1)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j++;
		i--;
	}
	return (str);
}

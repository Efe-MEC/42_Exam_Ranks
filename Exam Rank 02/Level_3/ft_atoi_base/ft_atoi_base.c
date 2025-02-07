static int	ft_isdigit(int c)
{
	return (('0' <= c) && (c <= '9'));
}

static int	ft_isupper(int c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

static int	ft_islower(char c)
{
	return ((c >= 'a') && (c <= 'z'));
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		result *= str_base;
		if (ft_isdigit(*str))
			result += (*str - '0');
		else if (ft_isupper(*str))
			result += (*str - '7');
		else if (ft_islower(*str))
			result += (*str - 'W');
		str++;
	}
	return (result * sign);
}

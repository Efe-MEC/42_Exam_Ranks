#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_print_nbr(unsigned int nbr, int base)
{
	char *base_set = "0123456789abcdef";
	int count = 0;

	if (nbr / base > 0)
		count += ft_print_nbr(nbr / base, base);
	count += ft_putchar(base_set[nbr % base]);
	return (count);
}

int ft_print_d(int nbr)
{
	int count;
	
	if (count < 0)
	{
		count += ft_putchar('-');
		if (nbr == -2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		nbr = -nbr;
	}
	count += ft_print_nbr((unsigned int)nbr, 10);
	return (count);
}

int ft_printf (char *str, ...)
{
	int i;
	int count;
	va_list ls;

	va_start(ls, str);
	if (str == NULL)
		return (0);
	i = 0;
	count == 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd')
				count += ft_print_d(va_arg(ls, int));
			else if (str[i + 1] == 'x')
				count += ft_print_nbr(va_arg(ls, unsigned int), 16);
			else if (str[i + 1] == 's')
				ft_putstr(va_arg(ls, char *));
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ls);
	return (count);
}
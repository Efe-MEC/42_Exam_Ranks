#include <unistd.h>

void ft_putnbr(int i)
{
	if (i >= 10)
		ft_putnbr(i / 10);
	char c = '0' + (i % 10);
	write(1, &c, 1);
}

int main (void)
{
	int i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0) 
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		i++;
		write (1, "\n", 1);
	}
}
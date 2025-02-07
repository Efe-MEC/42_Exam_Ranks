#include <unistd.h>
#include <stdlib.h>

static void	ft_putchar_fd(char character,	int file_descriptor)
{
	if (file_descriptor >= 0)
		write(file_descriptor, &character, sizeof(char));
}

static void	ft_small_put_nbr(int number)
{
	if (number > 9)
	{
		ft_small_put_nbr(number / 10);
		ft_small_put_nbr(number % 10);
	}
	else
		ft_putchar_fd((number + '0'), STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	(void)argv;
	ft_small_put_nbr(argc - 1);
	ft_putchar_fd((char)10, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

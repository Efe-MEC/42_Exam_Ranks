#include <unistd.h>
#include <stdlib.h>

static void	ft_putchar_fd(char character,	int file_descriptor)
{
	if (file_descriptor >= 0)
		write(file_descriptor, &character, sizeof(char));
}

static int	ft_small_atoi(char *string)
{
	int	result;

	result = 0;
	while (*string)
	{
		result *= 10;
		result += (*string - '0');
		string++;
	}
	return (result);
}

static void	ft_print_hex(int nbr)
{
	if (nbr >= 16)
		ft_print_hex(nbr / 16);
	ft_putchar_fd("0123456789abcdef"[nbr % 16], STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_hex(ft_small_atoi(argv[1]));
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}

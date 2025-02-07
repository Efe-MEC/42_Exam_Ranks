#include <unistd.h>
#include <stdlib.h>

static void	ft_expand_str(char *str)
{
	while (ft_isspace(*str))
		str++;
	while (*str)
	{
		if (ft_isspace(*str))
		{
			if (*(str + 1) > ' ' && *(str + 1) != '\0')
				ft_put_many_char (' ', 3);
		}
		else if (!ft_isspace(*str))
			ft_putchar_fd(*str, STDOUT_FILENO);
		str++;
	}
}

static void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, sizeof(char));
}

static void	ft_put_many_char(char c, int nbr)
{
	while (nbr--)
		ft_putchar_fd(c, STDOUT_FILENO);
}

static int	ft_isspace(int c)
{
	return ((c == ' ') || ((c >= '\t') && (c <= '\r')));
}
int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_expand_str(argv[0x1]);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

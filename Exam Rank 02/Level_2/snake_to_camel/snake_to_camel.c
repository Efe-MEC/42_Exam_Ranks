#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if(argv[1][i] == '_')
			{
				i++;
				if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
					argv[1][i] -= 32;
				write(1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
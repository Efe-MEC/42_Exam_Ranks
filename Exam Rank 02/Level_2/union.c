#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int map[256] = {0};

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			map[(int)argv[1][i]] = 1;
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			map[(int)argv[2][i]] = 1;
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			if (map[(int)argv[1][i]] == 1)
			{
				write(1, &argv[1][i], 1);
				map[(int)argv[1][i]] = 0;
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (map[(int)argv[2][i]] == 1)
			{
				write(1, &argv[2][i], 1);
				map[(int)argv[2][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

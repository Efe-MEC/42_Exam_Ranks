#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int len;
	const char *s1;
	const char *s2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		len = 0;
		i = 0;
		while (s1[len])
			len++;
		while (i < len && *s2)
		{
			if (s1[i] == *s2++)
				i++;
		}
		if (i == len)
			write(1, s1, len);
	}
	write(1, "\n", 1);
}

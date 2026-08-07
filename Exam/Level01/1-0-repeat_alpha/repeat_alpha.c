#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			n = 1;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				n = argv[1][i] - 'a' + 1;
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				n = argv[1][i] - 'A' + 1;
			while (n--)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

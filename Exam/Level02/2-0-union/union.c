#include <unistd.h>

int	main(int argc, char **argv)
{
	int			seen[256];
	int			i;
	int			j;
	unsigned char	c;

	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (argc == 3)
	{
		i = 1;
		while (i <= 2)
		{
			j = 0;
			while (argv[i][j])
			{
				c = (unsigned char)argv[i][j++];
				if (!seen[c] && ++seen[c])
					write(1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

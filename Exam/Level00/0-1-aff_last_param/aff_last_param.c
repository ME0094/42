#include <unistd.h>

static void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		putstr(argv[argc - 1]);
	write(1, "\n", 1);
	return (0);
}

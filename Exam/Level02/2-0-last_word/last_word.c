#include <unistd.h>

int	main(int argc, char **argv)
{
	int	end;
	int	start;

	if (argc == 2)
	{
		end = 0;
		while (argv[1][end])
			end++;
		while (end > 0 && (argv[1][end - 1] == ' ' || argv[1][end - 1] == '\t'))
			end--;
		start = end;
		while (start > 0 && argv[1][start - 1] != ' ' && argv[1][start - 1] != '\t')
			start--;
		write(1, argv[1] + start, end - start);
	}
	write(1, "\n", 1);
	return (0);
}

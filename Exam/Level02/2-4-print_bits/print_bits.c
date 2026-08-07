#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int			bit;
	char		value;

	bit = 7;
	while (bit >= 0)
	{
		value = ((octet >> bit) & 1) + '0';
		write(1, &value, 1);
		bit--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				bits;

	result = 0;
	bits = 8;
	while (bits--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}

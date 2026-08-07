int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				largest;

	if (len == 0)
		return (0);
	largest = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > largest)
			largest = tab[i];
		i++;
	}
	return (largest);
}

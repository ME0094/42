int	ft_atoi(const char *str)
{
	int	sign;
	int	value;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	value = 0;
	while (*str >= '0' && *str <= '9')
		value = value * 10 + *str++ - '0';
	return (value * sign);
}

char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	char	tmp;

	end = 0;
	while (str[end])
		end++;
	start = 0;
	while (start < --end)
	{
		tmp = str[start];
		str[start++] = str[end];
		str[end] = tmp;
	}
	return (str);
}

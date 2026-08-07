#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		length;

	length = 0;
	while (src[length])
		length++;
	copy = malloc((length + 1) * sizeof(char));
	if (!copy)
		return (0);
	copy[length] = '\0';
	while (length-- > 0)
		copy[length] = src[length];
	return (copy);
}

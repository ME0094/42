#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	struct s_list	*next;
	void				*data;
}t_list;

char	*ft_strdup(char *src);
int		*ft_rrange(int start, int end);
int		*ft_range(int start, int end);
char	*ft_itoa(int nbr);
char	*ft_itoa_base(int value, int base);
char	**ft_split(char *str);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

static int	compare(void *left, void *right)
{
	return (strcmp((char *)left, (char *)right));
}

static int	check_string(char *actual, const char *expected)
{
	int	ok;

	if (!actual)
		return (0);
	ok = strcmp(actual, expected) == 0;
	free(actual);
	return (ok);
}

static int	check_ranges(void)
{
	int	*range;
	int	*reverse;
	int	ok;

	range = ft_range(-2, 2);
	reverse = ft_rrange(-2, 2);
	if (!range || !reverse)
		return (free(range), free(reverse), 0);
	ok = range[0] == -2 && range[4] == 2;
	ok = ok && reverse[0] == 2 && reverse[4] == -2;
	free(range);
	free(reverse);
	return (ok);
}

static int	check_split(void)
{
	char	**words;
	int		i;
	int		ok;

	words = ft_split("  alpha\tbeta\ngamma  ");
	if (!words)
		return (0);
	ok = words[0] && words[1] && words[2] && !words[3];
	ok = ok && strcmp(words[0], "alpha") == 0;
	ok = ok && strcmp(words[1], "beta") == 0;
	ok = ok && strcmp(words[2], "gamma") == 0;
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (ok);
}

static t_list	*node(char *data, t_list *next)
{
	t_list	*item;

	item = malloc(sizeof(t_list));
	if (!item)
		return (0);
	item->data = data;
	item->next = next;
	return (item);
}

static int	check_list_removal(void)
{
	t_list	*list;
	t_list	*next;

	list = node("keep", node("drop", node("drop", 0)));
	if (!list || !list->next || !list->next->next)
		return (0);
	ft_list_remove_if(&list, "drop", compare);
	if (!list || list->next || strcmp(list->data, "keep") != 0)
		return (0);
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	return (1);
}

int	main(void)
{
	int	ok;

	ok = check_string(ft_strdup("memory"), "memory");
	ok = ok && check_string(ft_itoa(INT_MIN), "-2147483648");
	ok = ok && check_string(ft_itoa_base(-42, 10), "-42");
	ok = ok && check_string(ft_itoa_base(255, 16), "FF");
	ok = ok && check_ranges();
	ok = ok && check_split();
	ok = ok && check_list_removal();
	if (!ok)
		return (1);
	printf("dynamic-memory functions: OK\n");
	return (0);
}

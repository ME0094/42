/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	words(char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (space(*s))
			s++;
		if (*s)
			n++;
		while (*s && !space(*s))
			s++;
	}
	return (n);
}

static char	*copy_word(char *str, int length)
{
	char	*word;
	int		i;

	word = malloc(length + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	char	**out;
	int		i;
	int		len;

	i = 0;
	out = malloc(sizeof(char *) * (words(s) + 1));
	if (!out)
		return (0);
	while (*s)
	{
		while (space(*s))
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && !space(s[len]))
			len++;
		out[i] = copy_word(s, len);
		if (!out[i])
			return (0);
		i++;
		s += len;
	}
	out[i] = 0;
	return (out);
}

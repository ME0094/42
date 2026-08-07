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

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_is_separator(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_copy_word(char *str, int length)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (length + 1));
	if (word == 0)
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

int	ft_fill_words(char **result, char *str, char *charset)
{
	int	i;
	int	start;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_separator(str[i], charset))
			i++;
		start = i;
		while (str[i] != '\0' && !ft_is_separator(str[i], charset))
			i++;
		if (i > start)
		{
			result[word] = ft_copy_word(&str[start], i - start);
			if (result[word++] == 0)
				return (-1);
		}
	}
	result[word] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	if (result == 0)
		return (0);
	if (ft_fill_words(result, str, charset) < 0)
		return (0);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	ft_put_error(char *program, char *name)
{
	write(2, basename(program), ft_strlen(basename(program)));
	write(2, ": ", 2);
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

int	ft_cat_fd(int file)
{
	char	buffer[4096];
	int		count;

	count = read(file, buffer, sizeof(buffer));
	while (count > 0)
	{
		write(1, buffer, count);
		count = read(file, buffer, sizeof(buffer));
	}
	return (count >= 0);
}

void	ft_cat_file(char *program, char *name)
{
	int	file;

	file = open(name, O_RDONLY);
	if (file < 0)
		ft_put_error(program, name);
	else
	{
		if (ft_cat_fd(file) == 0)
			ft_put_error(program, name);
		close(file);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_cat_fd(0);
	i = 1;
	while (i < argc)
	{
		ft_cat_file(argv[0], argv[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_read_fd(t_dump *dump, int file)
{
	char	buffer[4096];
	int		count;

	count = read(file, buffer, sizeof(buffer));
	while (count > 0)
	{
		ft_feed(dump, buffer, count);
		count = read(file, buffer, sizeof(buffer));
	}
}

void	ft_read_file(t_dump *dump, char *program, char *name)
{
	int	file;

	file = open(name, O_RDONLY);
	if (file < 0)
		ft_error(program, name);
	else
	{
		ft_read_fd(dump, file);
		close(file);
	}
}

int	main(int argc, char **argv)
{
	t_dump	dump;
	int		i;

	dump.offset = 0;
	dump.length = 0;
	dump.has_previous = 0;
	dump.repeated = 0;
	if (argc == 1)
		ft_read_fd(&dump, 0);
	i = 1;
	while (i < argc)
		ft_read_file(&dump, argv[0], argv[i++]);
	ft_finish(&dump);
	return (0);
}

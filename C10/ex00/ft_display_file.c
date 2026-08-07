/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_display_file(char *name)
{
	char	buffer[4096];
	int		file;
	int		count;

	file = open(name, O_RDONLY);
	if (file < 0)
		return (0);
	count = read(file, buffer, sizeof(buffer));
	while (count > 0)
	{
		write(1, buffer, count);
		count = read(file, buffer, sizeof(buffer));
	}
	close(file);
	return (count == 0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (ft_display_file(argv[1]) == 0)
		write(2, "Cannot read file.\n", 18);
	return (0);
}

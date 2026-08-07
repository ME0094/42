/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <unistd.h>

typedef struct s_dump
{
	unsigned char	line[16];
	unsigned char	previous[16];
	unsigned int	offset;
	int				length;
	int				has_previous;
	int				repeated;
}	t_dump;

void	ft_put_hex(unsigned int value, int digits);
void	ft_print_line(t_dump *dump);
void	ft_feed(t_dump *dump, char *buffer, int count);
void	ft_finish(t_dump *dump);
void	ft_error(char *program, char *name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zenkri <zenkri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:52:56 by zenkri            #+#    #+#             */
/*   Updated: 2023/12/08 17:11:41 by zenkri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_file_count(char *filepath)
{
	int		file;
	int		size;
	int		sizetot;
	char	buf[__BUFF];

	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		sizetot = 0;
		size = read(file, buf, __BUFF);
		while (size != 0)
		{
			sizetot += size;
			size = read(file, buf, __BUFF);
		}
		close(file);
		return (sizetot);
	}
	else
		return (-1);
}

void	ft_print_rest(int file, char *buf, int bufsize)
{
	while (bufsize != 0)
	{
		ft_putstr_buf(buf, bufsize);
		bufsize = read(file, buf, __BUFF);
	}
}

void	ft_file_get(char *filepath, int sizetot, int size)
{
	int		i;
	int		bufsize;
	int		file;
	char	buf[__BUFF];

	file = open(filepath, O_RDWR);
	i = 0;
	bufsize = read(file, buf, __BUFF);
	while (bufsize != 0 && ((i + 1) * __BUFF < sizetot - size))
	{
		i++;
		bufsize = read(file, buf, __BUFF);
	}
	if (size >= sizetot)
		i = -1;
	else
		i = (sizetot - size) - (i * __BUFF) - 1;
	while (++i < __BUFF && i < bufsize)
		ft_putchar(buf[i], 1);
	bufsize = read(file, buf, __BUFF);
	ft_print_rest(file, buf, bufsize);
	close(file);
}

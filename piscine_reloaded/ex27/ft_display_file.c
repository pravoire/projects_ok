/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:37:22 by pravoire          #+#    #+#             */
/*   Updated: 2016/11/07 18:00:51 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

static void		ft_putendl(char *s)
{
	int			i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

static void		error(int n)
{
	if (n == 0)
		ft_putendl("File name missing.");
	else if (n == 1)
		ft_putendl("Too many arguments.");
	else if (n == 2)
		ft_putendl("Unable to open given file.");
	else if (n == 3)
		ft_putendl("Error reading data source.");
}

int				main(int ac, char **av)
{
	char		buf;
	int			fd;
	int			rd_res;

	if (ac < 2)
		error(0);
	else if (ac > 2)
		error(1);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			error(2);
		else
		{
			while ((rd_res = read(fd, &buf, 1)))
				write(1, &buf, 1);
			if (rd_res != 0)
				error(3);
		}
		close(fd);
	}
	return (0);
}

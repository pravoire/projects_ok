/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:01:08 by pravoire          #+#    #+#             */
/*   Updated: 2016/11/07 16:04:11 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_putendl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	ft_putchar('\n');
}

int			main(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
		ft_putendl(av[i++]);
	return (0);
}

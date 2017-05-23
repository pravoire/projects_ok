/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 00:40:23 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/11 22:36:12 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd((n % 10) + 48, fd);
		}
		else
			ft_putchar_fd(n + 48, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		if (n < -9)
		{
			ft_putnbr_fd((n / 10) * -1, fd);
			ft_putchar_fd(((n % 10) * -1) + 48, fd);
		}
		else
			ft_putchar_fd((n * -1) + 48, fd);
	}
}

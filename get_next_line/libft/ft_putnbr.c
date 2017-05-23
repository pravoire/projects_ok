/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 00:15:22 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/05 00:31:31 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 0)
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putchar((n % 10) + 48);
		}
		else
			ft_putchar(n + 48);
	}
	else
	{
		ft_putchar('-');
		if (n < -9)
		{
			ft_putnbr((n / 10) * -1);
			ft_putchar(((n % 10) * -1) + 48);
		}
		else
			ft_putchar((n * -1) + 48);
	}
}

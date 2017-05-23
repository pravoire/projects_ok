/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:15:21 by pravoire          #+#    #+#             */
/*   Updated: 2016/11/07 14:32:51 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int	res;

	if (nb >= 13 || nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	res = nb;
	while (--nb > 1)
		res *= nb;
	return (res);
}

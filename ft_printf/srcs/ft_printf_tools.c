/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:23:30 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:46:51 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*tool_ujtoa(uintmax_t val, int base, \
			t_printf_mod mod, char *cp)
{
	int		maybevalisequaltozero;

	maybevalisequaltozero = 1;
	while (val || maybevalisequaltozero)
	{
		maybevalisequaltozero = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? \
			(t_uchar)mod.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mod.flag & ALT) && *cp != '0')
		*--cp = '0';
	return (cp);
}

char		*tool_ultoa(t_ulong val, int base, \
			t_printf_mod mod, char *cp)
{
	int		maybevalisequaltozero;

	maybevalisequaltozero = 1;
	while (val || maybevalisequaltozero)
	{
		maybevalisequaltozero = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? \
			(t_uchar)mod.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mod.flag & ALT) && *cp != '0')
		*--cp = '0';
	return (cp);
}

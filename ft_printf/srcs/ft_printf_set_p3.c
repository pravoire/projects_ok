/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_p3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:36:49 by pravoire          #+#    #+#             */
/*   Updated: 2017/05/08 17:39:39 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_prec(t_printf_mod *mod, const char *fmt, va_list ap)
{
	int	n;

	if (*++fmt == '*')
	{
		mod->prec = va_arg(ap, int);
		return (2);
	}
	mod->prec = ft_atoi(fmt);
	n = 1;
	while (ft_isdigit(*fmt++))
		n++;
	return (n);
}

int		set_width(t_printf_mod *mod, const char *fmt)
{
	int	n;

	n = 0;
	mod->width = ft_atoi(fmt);
	while (ft_isdigit(*fmt++))
		n++;
	return (n);
}

int		set_aster(t_printf_mod *mod, const char *fmt, va_list ap)
{
	int	width;

	width = va_arg(ap, int);
	if (width < 0)
	{
		mod->flag |= LADJUST;
		mod->width = -width;
	}
	else
		mod->width = width;
	return (1);
	if (fmt)
		return (1);
}

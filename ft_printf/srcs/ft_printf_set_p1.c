/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_p1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:34:35 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:45:45 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_space(t_printf_mod *mod)
{
	if (!mod->sign)
		mod->sign = ' ';
	return (1);
}

int	set_plus(t_printf_mod *mod)
{
	mod->sign = '+';
	return (1);
}

int	set_alt(t_printf_mod *mod)
{
	mod->flag |= ALT;
	return (1);
}

int	set_minus(t_printf_mod *mod)
{
	mod->flag |= LADJUST;
	return (1);
}

int	set_zero(t_printf_mod *mod)
{
	mod->flag |= ZEROPAD;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:36:10 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:45:55 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_h(t_printf_mod *mod)
{
	if (mod->flag & SHORTINT)
	{
		mod->flag &= ~SHORTINT;
		mod->flag |= CHARINT;
	}
	else
		mod->flag |= SHORTINT;
	return (1);
}

int	set_l(t_printf_mod *mod)
{
	if (mod->flag & LONGINT)
	{
		mod->flag &= ~LONGINT;
		mod->flag |= LLONGINT;
	}
	else
		mod->flag |= LONGINT;
	return (1);
}

int	set_j(t_printf_mod *mod)
{
	mod->flag |= INTMAXT;
	return (1);
}

int	set_z(t_printf_mod *mod)
{
	mod->flag |= SIZET;
	return (1);
}

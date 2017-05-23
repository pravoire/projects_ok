/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:33:40 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 18:39:07 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				set_fmt_mod(const char *fmt, \
				t_printf_mod *mod, t_printf_set_function *set_mod, va_list ap)
{
	const char	*cp;
	int			index;

	cp = ++fmt;
	while (*fmt)
	{
		index = get_mod_index(MOD_CSET, *fmt);
		if (index == -1)
			break ;
		fmt += set_mod[index](mod, fmt, ap);
	}
	mod->spec = *fmt;
	return (fmt - (cp - 1));
}

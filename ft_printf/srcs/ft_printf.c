/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:38:18 by pravoire          #+#    #+#             */
/*   Updated: 2017/05/08 17:42:31 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int					print_no_fmt(const char *format)
{
	const char				*cp;
	const char				*tmp;

	cp = format;
	tmp = cp;
	while (*format && *format != '%')
		format++;
	save_buf((void *)tmp, format - tmp);
	return (format - cp);
}

int							ft_vlprintf(const char *format, va_list ap)
{
	t_printf_spec_function	print_fmt[NB_SPEC_FUNCTION];
	t_printf_set_function	set_mod[NB_MOD_FUNCTION];
	t_printf_mod			mod;
	int						len;
	long int				tlen;

	ini_print(print_fmt);
	ini_set(set_mod);
	tlen = 0;
	while (*format)
	{
		len = print_no_fmt(format);
		tlen += len;
		if (!*(format += len))
			break ;
		ft_bzero((void *)&mod, sizeof(t_printf_mod));
		mod.prec = -1;
		if (*(format += set_fmt_mod(format, &mod, set_mod, ap)))
			format++;
		tlen += print_fmt[get_spec_index(SPEC_CSET, mod.spec)](mod, ap);
	}
	return (tlen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:31:11 by pravoire          #+#    #+#             */
/*   Updated: 2017/05/08 17:40:24 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ini_print(t_printf_spec_function *print_fmt)
{
	print_fmt[0] = print_d;
	print_fmt[1] = print_d;
	print_fmt[2] = print_ld;
	print_fmt[3] = print_x;
	print_fmt[4] = print_lx;
	print_fmt[5] = print_u;
	print_fmt[6] = print_lu;
	print_fmt[7] = print_o;
	print_fmt[8] = print_lo;
	print_fmt[9] = print_p;
	print_fmt[10] = print_s;
	print_fmt[11] = print_ls;
	print_fmt[12] = print_c;
	print_fmt[13] = print_lc;
	print_fmt[14] = (t_printf_spec_function)print_def;
}

void	ini_set(t_printf_set_function *set_mod)
{
	set_mod[0] = (t_printf_set_function)set_alt;
	set_mod[1] = (t_printf_set_function)set_space;
	set_mod[2] = (t_printf_set_function)set_plus;
	set_mod[3] = (t_printf_set_function)set_minus;
	set_mod[4] = (t_printf_set_function)set_zero;
	set_mod[5] = set_prec;
	set_mod[6] = (t_printf_set_function)set_h;
	set_mod[7] = (t_printf_set_function)set_l;
	set_mod[8] = (t_printf_set_function)set_j;
	set_mod[9] = (t_printf_set_function)set_z;
	set_mod[10] = set_aster;
	set_mod[11] = (t_printf_set_function)set_width;
}

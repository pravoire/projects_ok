/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getindex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:28:49 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:47:07 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_mod_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	if (f)
		return (f - cset);
	else if (ft_isdigit(c))
		return (NB_MOD_FUNCTION - 1);
	else
		return (-1);
}

int			get_spec_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	return (f ? f - cset : NB_SPEC_FUNCTION - 1);
}

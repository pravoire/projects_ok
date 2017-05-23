/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:35:56 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:15:52 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include "ft_header.h"

# define MASK1 49280
# define MASK2 14712960
# define MASK3 4034953344

size_t		ft_wclen(wchar_t *s);
void		ft_wctoa(wchar_t *ws, char *s);

#endif

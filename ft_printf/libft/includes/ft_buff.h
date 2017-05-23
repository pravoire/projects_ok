/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:45:37 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:15:24 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFF_H
# define FT_BUFF_H

# include "ft_header.h"

typedef struct	s_buff
{
	int			ret;
	int			fd;
	size_t		buff_size;
	char		*buff;
}				t_buff;

t_buff			*ft_buffnew(int fd, size_t buff_size);
void			ft_buffexp(t_buff **buff, size_t buff_size);
void			ft_buffdel(t_buff **buff);

#endif

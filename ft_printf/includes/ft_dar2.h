/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:54:51 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:40:09 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DAR2_H
# define FT_DAR2_H

# include "ft_header.h"
# include "ft_mem.h"

# define DAR2_OFFSET 32

typedef void	(*t_dar_del)(void *);

typedef struct	s_dar2
{
	void		**ar;
	size_t		size_content;
	size_t		size;
	size_t		size_max;
	t_dar_del	del;
}				t_dar2;

int				ft_dar2new(t_dar2 *dar, size_t size, t_dar_del del);
int				ft_dar2add(t_dar2 *dar, void *data);
void			ft_dar2dump(t_dar2 *dar, void (*f)(void *));
int				ft_dar2del(t_dar2 *dar);

#endif

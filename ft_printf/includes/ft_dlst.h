/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:11:37 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:40:30 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLST_H
# define FT_DLST_H

# include "ft_header.h"
# include "ft_mem.h"

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*p;
	struct s_dlist	*n;
}					t_dlist;

t_dlist				*ft_dlstnew(const void *content, size_t content_size);
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstaddp(t_dlist **alst, t_dlist *elem);
void				ft_dlstaddn(t_dlist **alst, t_dlist *elem);
void				ft_dlstaddip(t_dlist **alst, t_dlist *elem, t_uint i);
void				ft_dlstaddin(t_dlist **alst, t_dlist *elem, t_uint i);
t_dlist				*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *));

#endif

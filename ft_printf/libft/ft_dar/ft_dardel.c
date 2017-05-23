/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:31:41 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:02:04 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar.h"

void	ft_dardel(t_dar *ar)
{
	free(ar->data);
	free(ar->address);
	ft_bzero((void *)ar, sizeof(t_dar));
}

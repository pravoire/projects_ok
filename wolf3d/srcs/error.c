/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:29:30 by pravoire          #+#    #+#             */
/*   Updated: 2017/05/09 16:03:53 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error_malloc(void)
{
	ft_putendl("ERROR ALLOCATING MEMORY");
	exit(1);
}

void	error_arg(void)
{
	ft_putendl("Argument provided isn't correct.");
	ft_putendl("Use the following prototype : <executable> <path_to_map>");
	exit(1);
}

void	error_map(void)
{
	ft_putendl("The specified map contains errors and cannot be used.");
	exit(1);
}

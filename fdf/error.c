/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:32:46 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/10 18:41:46 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(int code)
{
	if (code == 0)
		ft_putendl("Too few or too much arguments provided. Exiting program.");
	else if (code == 1)
		ft_putendl("Error allocating memory. Exiting program.");
	else if (code == 2)
		ft_putendl("Error initializing mlx object. Exiting program.");
	else if (code == 3)
		ft_putendl("Error creating new window. Exiting program.");
	else if (code == 4)
		ft_putendl("Error reading data source. Exiting program.");
	else if (code == 5)
		ft_putendl("Error creating new image. Exiting program.");
	else if (code == 6)
		ft_putendl("Invalid map. Exiting program.");
	exit(1);
}

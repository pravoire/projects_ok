/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:42:24 by pravoire          #+#    #+#             */
/*   Updated: 2017/05/09 15:32:53 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	expose_hook(t_env *e)
{
	draw_img(e);
	return (0);
}

void		param_error(int n)
{
	if (n == 1)
		ft_putendl("The attempt to malloc has failed");
	else
	{
		ft_putendl("Unexpected parameter used !");
		ft_putendl("Choose one of the following :");
		ft_putendl("Mandelbrot, Julia, Menger, B_Ship or Mandelbar");
	}
	exit(1);
}

static void	check_params(int ac, char **av)
{
	if (ac != 2)
		param_error(2);
	if (ft_strcmp(av[1], "Mandelbrot") != 0 &&\
			ft_strcmp(av[1], "Julia") != 0 &&\
			ft_strcmp(av[1], "Mandelbar") != 0 &&\
			ft_strcmp(av[1], "B_Ship") != 0 &&\
			ft_strcmp(av[1], "Menger") != 0)
		param_error(2);
}

static void	usable_key(void)
{
	ft_putendl("Here is a list of the usable key :");
	ft_putendl("ESC or Q to exit the program");
	ft_putendl("R to reload all the fractals");
	ft_putendl("The arrow keys to move the picture in the window");
	ft_putendl("+ or - on the numeric pad to zoom or dezoom");
	ft_putendl("You can zoom & dezoom with the clics of the mouse or srolling");
	ft_putendl("1-5 on the numeric pad to change fractal");
	ft_putendl("1-4 on the keyboard to switch colors");
}

int			main(int ac, char **av)
{
	t_env	*e;

	check_params(ac, av);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		param_error(1);
	e->height = HEIGHT;
	e->width = WIDTH;
	e->stop_motion = 1;
	e->av = av;
	open_window("42 Fractol", e);
	init_fractol(e);
	init_color(e);
	fractol_change(av[1], e);
	usable_key();
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse, e);
	mlx_hook(e->win, PRESS, PRESS_MASK, key, e);
	mlx_hook(e->win, MOTION_NOTIFY, MOTION_MASK, motion, e);
	mlx_loop(e->mlx);
	return (0);
}

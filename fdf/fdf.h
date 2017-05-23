/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 10:21:54 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/10 19:09:26 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define WIN_W 1024
# define WIN_H 768

# define ESC 53
# define M_UP 126
# define M_DOWN 125
# define M_LEFT 123
# define M_RIGHT 124
# define Z_UP 116
# define Z_DOWN 121
# define Z_RESET 115
# define Z_STEP 8

typedef struct		s_pts
{
	int				z;
	float			x_i;
	float			y_i;
}					t_pts;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				img_w;
	int				img_h;
	float			x_min;
	float			x_max;
	float			y_min;
	float			y_max;
	int				bpp;
	int				s_l;
	int				end;
	char			*data;
	t_pts			**map;
	int				map_w;
	int				map_h;
	int				x0;
	int				y0;
	int				z_max;
	int				z_min;
	float			scl;
	unsigned char	rgb[3];
}					t_env;

void				error(int code);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				get_map_size(t_env *e, char *s);
void				get_map_pts(t_env *e, char *s);
void				draw(t_env *e);
void				map_to_iso(t_env *e);
t_pts				pt_to_iso(t_env *e, float x, float y, int z);
void				get_pt_color(t_env *e, t_pts p1, t_pts p2);
void				draw_line(t_env *e, t_pts p1, t_pts p2);
void				quad_1(t_env *e, t_pts p1, t_pts p2);
void				quad_2(t_env *e, t_pts p1, t_pts p2);
void				quad_3(t_env *e, t_pts p1, t_pts p2);
void				quad_4(t_env *e, t_pts p1, t_pts p2);
void				draw_pts(t_env *e, t_pts p1, t_pts p2);

#endif

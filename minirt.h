/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:50:25 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 18:02:24 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

# define WINDOW_X 1920;
# define WINDOW_Y 1080;

typedef enum e_shape
{
	sphere = 0,
	plane,
	cylinder,
	con,
	hyperboloid,
	paraboloid
}	t_shape;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_light
{
	struct s_point	point;
	float			light_ratio;
	uint32_t		color;
}	t_light;

typedef struct s_camera
{
	t_point	point;
	t_point	n_vector;
	size_t	fov;
}	t_camera;

typedef struct s_object
{
	t_shape		shape;
	t_point		point;
	t_point		n_vector;
	size_t		diameter;
	size_t		height;
	uint32_t	color;
}	t_object;

//mlx image 관련 구조체
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_data
{
	struct s_light	a_light;
	struct s_camera	camera;
	struct s_mlx	params;
	struct s_light	*lights;
	struct s_object	*objects;
}	t_data;

int		init_img (t_data *data);
void	print_img(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_hooks(t_data *data);
int		key_hook(int keycode, t_data *data);
#endif

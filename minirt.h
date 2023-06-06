/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:50:25 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/06 20:25:12 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
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

typedef struct s_data
{
	struct s_light	a_light;
	struct s_camera	camera;
	struct s_light	*lights;
	struct s_object	*objects;
}	t_data;

#endif

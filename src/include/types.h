/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:57 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 01:58:44 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>

# define ARR_SIZE 5

typedef enum e_shape
{
	sphere = 4,
	plane,
	cylinder,
	con,
	hyperboloid,
	paraboloid
}	t_shape;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
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
	int		fov;
}	t_camera;

typedef struct s_object
{
	t_shape		shape;
	t_point		point;
	t_point		n_vector;
	float		diameter;
	float		height;
	uint32_t	color;
}	t_object;

typedef struct s_data
{
	struct s_light	a_light;
	struct s_camera	camera;
	struct s_light	**lights;
	struct s_object	**objects;
}	t_data;

t_object	**create_objlist(int n);
void		add_objlist(t_object *obj, t_object ***objlist);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:11:06 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/19 18:25:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	hit_objs(t_ray *ray, t_object *obj, double value[])
{
	int	value_num;

	value[0] = -1.0;
	value[1] = -1.0;
	value_num = 0;
	if (obj->shape == sphere)
		value_num = hit_sphere(ray, obj, value);
	else if (obj->shape == plane)
		value_num = hit_plane(ray, obj, value);
	else if (obj->shape == cylinder)
		value_num = hit_cylinder(ray, obj, value);
	else
		value_num = hit_con(ray, obj, value);
	return (value_num);
}

static double	calc_tmin(int value_num, double value[], const double t_min)
{
	if (value_num == 0 || \
		(value_num == 1 && value[0] < t_min) || \
		(value_num == 2 && (value[0] < t_min && value[1] < t_min)))
		return (-1.0);
	else if (value_num == 2 && value[0] < t_min)
		return (value[1]);
	return (value[0]);
}

static double	is_flag(t_camera *cam, t_object *obj, \
									double value[], int value_num)
{
	const double	t_min = cam->focal_length \
							/ v_dot(cam->n_vector, (cam->ray).dir);
	double			ret;
	t_ray			viewport_ray;

	ret = calc_tmin(value_num, value, t_min);
	if (ret == -1)
	{
		viewport_ray.dir = (cam->ray).dir;
		viewport_ray.origin_point = v_mul_val((cam->ray).dir, t_min);
		value_num = hit_objs(&viewport_ray, obj, value);
		ret = calc_tmin(value_num, value, 0);
	}
	return (ret);
}

static double	get_tmp(t_camera *cam, t_object *obj, int flag)
{
	int				value_num;
	double			value[2];

	value_num = hit_objs(&(cam->ray), obj, value);
	if (flag)
		return (is_flag(cam, obj, value, value_num));
	if (value[0] < 0)
	{
		if (value_num == 2 && value[1] >= 0)
			return (value[1]);
		return (-1);
	}
	return (value[0]);
}

u_int32_t	create_trgb(t_data *data, int flag)
{
	u_int32_t	color;
	size_t		i;
	double		t;
	double		tmp;

	color = 0;
	t = MAXFLOAT;
	i = 0;
	while ((data->objects)[i])
	{
		tmp = get_tmp(&(data->camera), data->objects[i], flag);
		if (tmp >= 0 && t > tmp)
		{
			t = tmp;
			color = (data->objects)[i]->color;
		}
		i++;
	}
	return (color);
}

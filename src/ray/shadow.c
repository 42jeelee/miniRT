/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/07 21:37:56 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	only_hit_objs(t_ray *ray, t_object *obj)
{
	int		value_num;
	double	value[2];

	value_num = 0;
	value[0] = -1;
	value[1] = -1;
	if (obj->shape == sphere)
		value_num = hit_sphere(ray, obj, value);
	else if (obj->shape == plane)
		value_num = hit_plane(ray, obj, value);
	else if (obj->shape == cylinder)
		value_num = hit_cylinder(ray, obj, value) + \
			only_hit_circle(ray, obj, value);
	else if (obj->shape == cone)
		value_num = hit_cone(ray, obj, value) + \
			only_hit_circle(ray, obj, value);
	if (value[0] < 0)
	{
		if (value_num == 2 && value[1] >= 0)
			return (value[1]);
		return (-1);
	}
	return (value[0]);
}

int	is_shadow(t_object **objs, t_light *light, t_point frag_point)
{
	t_point	l_sub_p;
	t_ray	ray;
	double	max;
	double	t;
	int		i;

	l_sub_p = v_sub_vec(light->point, frag_point);
	max = v_length(l_sub_p);
	ray.origin_point = frag_point;
	ray.dir = v_unit(l_sub_p);
	i = -1;
	while (objs[++i])
	{
		t = only_hit_objs(&ray, objs[i]);
		if (0.00001 < t && t <= max)
			return (1);
	}
	return (0);
}

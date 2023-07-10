/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/10 01:17:35 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	check_block(t_ray *ray, t_object *obj)
{
	double	t;
	double	circle_dist;

	t = hit_objs(ray, obj);
	if (obj->shape == cylinder || obj->shape == cone)
	{
		circle_dist = hit_circle(ray, obj);
		if (0 <= circle_dist && (t < 0 || circle_dist < t))
			return (circle_dist);
	}
	return (t);
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
		t = check_block(&ray, objs[i]);
		if (0.00001 < t && t <= max)
			return (1);
	}
	return (0);
}

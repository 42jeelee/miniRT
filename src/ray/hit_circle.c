/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:58:16 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/09 18:18:21 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	_hit_circle(t_point h, t_ray *ray, t_object *obj)
{
	double	t;
	double	dist_p_h;
	t_point	p;

	t = v_length(v_sub_vec(ray->origin_point, h)) * \
		fabs(v_dot(v_unit(v_sub_vec(ray->origin_point, h)), obj->n_vector)) / \
		fabs(v_dot(ray->dir, obj->n_vector));
	p = v_add_vec(ray->origin_point, v_mul_val(ray->dir, t));
	dist_p_h = fabs(v_length(v_sub_vec(p, h)));
	if (dist_p_h > obj->diameter / 2)
		return (-1);
	return (t);
}

int	hit_circle(t_ray *ray, t_object *obj)
{
	double	b_value;
	double	t_value;
	t_point	h;

	if (v_dot(ray->dir, obj->n_vector) == 0)
		return (0);
	h = v_add_vec(obj->point, v_mul_val(obj->n_vector, obj->height / 2));
	b_value = _hit_circle(h, ray, obj);
	if (obj->shape == cylinder)
	{
		h = v_add_vec(obj->point, v_mul_val(obj->n_vector, -(obj->height / 2)));
		t_value = _hit_circle(h, ray, obj);
		if (t_value >= 0 && t_value < b_value)
			b_value = t_value;
	}
	if (b_value < 0)
		return (-1);
	return (b_value);
}

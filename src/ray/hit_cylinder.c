/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:31:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/27 16:29:01 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	cylinder_height(t_ray *ray, t_object *obj, double *value)
{
	t_point	p;
	t_point	p_sub_c;
	double	p_height;

	p = v_add_vec(ray->origin_point, v_mul_val(ray->dir, *value));
	p_sub_c = v_sub_vec(p, obj->point);
	p_height = v_dot(p_sub_c, obj->n_vector);
	if (0 > p_height || obj->height <= p_height)
	{
		*value = -1;
		return (-1);
	}
	*value = v_length(p);
	return (0);
}

int	cylinder_inf(t_ray *ray, t_object *obj, double *value)
{
	t_point	c_sub_o;

	c_sub_o = v_sub_vec(obj->point, ray->origin_point);
	*value = v_dot(c_sub_o, ray->dir);
	return (1);
}

int	hit_cylinder(t_ray *ray, t_object *obj, double value[])
{
	t_point	o_sub_c;
	double	a;
	double	b;
	double	c;
	int		value_num;

	o_sub_c = v_sub_vec(ray->origin_point, obj->point);
	a = v_dot(ray->dir, ray->dir) - \
		pow(v_dot(ray->dir, obj->n_vector), 2);
	b = 2 * (v_dot(ray->dir, o_sub_c) - \
		(v_dot(ray->dir, obj->n_vector) * v_dot(o_sub_c, obj->n_vector)));
	c = v_dot(o_sub_c, o_sub_c) - \
		pow(v_dot(o_sub_c, obj->n_vector), 2) - pow(obj->diameter / 2, 2);
	if ((b * b - 4 * a * c) == 0 && fabs(v_dot(ray->dir, obj->n_vector)) == 1)
		return (cylinder_inf(ray, obj, &value[0]));
	value_num = r_formula(a, b, c, value);
	value_num += cylinder_height(ray, obj, &value[0]) + \
		cylinder_height(ray, obj, &value[1]);
	return (value_num);
}

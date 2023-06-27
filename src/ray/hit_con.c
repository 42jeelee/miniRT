/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_con.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:38:03 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/27 16:26:17 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	con_height(t_ray *ray, t_object *obj, double *value)
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

int	con_inf(t_ray *ray, t_object *obj, double *value)
{
	t_point	h;
	double	h_o;
	double	p_h;

	h = v_sub_vec(obj->point, v_mul_val(obj->n_vector, obj->height));
	h_o = v_length(v_sub_vec(ray->origin_point, h));
	p_h = sqrt(pow(obj->diameter / 2, 2) + pow(obj->height, 2));
	*value = h_o - p_h;
	return (1);
}

int	hit_con(t_ray *ray, t_object *obj, double value[])
{
	t_point	o_sub_h;
	double	a;
	double	b;
	double	c;
	int		value_num;

	o_sub_h = v_sub_vec(ray->origin_point, \
		v_sub_vec(obj->point, v_mul_val(obj->n_vector, obj->height)));
	a = v_dot(ray->dir, ray->dir) - ((pow(obj->diameter / 2, 2) / \
		pow(obj->height, 2)) * pow(v_dot(ray->dir, obj->n_vector), 2)) - \
		pow(v_dot(ray->dir, obj->n_vector), 2);
	b = 2 * (v_dot(ray->dir, o_sub_h) - ((pow(obj->diameter / 2, 2) / \
		pow(obj->height, 2)) * v_dot(ray->dir, obj->n_vector) * \
		v_dot(o_sub_h, obj->n_vector)) - (v_dot(ray->dir, obj->n_vector) * \
		v_dot(o_sub_h, obj->n_vector)));
	c = v_dot(o_sub_h, o_sub_h) - ((pow(obj->diameter / 2, 2) / \
		pow(obj->height, 2)) * pow(v_dot(o_sub_h, obj->n_vector), 2)) - \
		pow(v_dot(o_sub_h, obj->n_vector), 2);
	if ((b * b - 4 * a * c) == 0 && fabs(v_dot(ray->dir, obj->n_vector)) == 1)
		return (con_inf(ray, obj, &value[0]));
	value_num = r_formula(a, b, c, value);
	value_num += con_height(ray, obj, &value[0]) + \
		con_height(ray, obj, &value[1]);
	return (value_num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:46:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/05 21:28:37 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	hit_objs(t_ray *ray, t_object *obj, t_rec *rec)
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
			hit_circle(ray, obj, value, rec);
	else if (obj->shape == cone)
		value_num = hit_cone(ray, obj, value) + \
			hit_circle(ray, obj, value, rec);
	if (value[0] < 0)
	{
		if (value_num == 2 && value[1] >= 0)
			return (value[1]);
		return (-1);
	}
	return (value[0]);
}

static t_point	_get_n_vector(t_ray *ray, t_point p, \
										t_shape hit_shape, t_object *obj)
{
	t_point	c;
	t_point	p_sub_o;
	t_point	q_sub_o;

	(void)ray;
	p_sub_o = set_vec(0, 0, 0);
	q_sub_o = set_vec(0, 0, 0);
	if (hit_shape == cylinder)
	{
		p_sub_o = v_sub_vec(p, obj->point);
		q_sub_o = v_add_vec(obj->point, v_mul_val(obj->n_vector, \
												v_dot(p_sub_o, obj->n_vector)));
	}
	else if (hit_shape == cone)
	{
		c = v_add_vec(obj->point, v_mul_val(obj->n_vector, -(obj->height / 2)));
		p_sub_o = v_sub_vec(p, c);
		q_sub_o = v_add_vec(c, v_mul_val(obj->n_vector, \
					v_length(p_sub_o) / v_dot(v_unit(p_sub_o), obj->n_vector)));
	}
	return (v_sub_vec(p_sub_o, q_sub_o));
}

static t_point	get_n_vector(t_ray *ray, t_point p, \
										t_shape hit_shape, t_object *obj)
{
	if (hit_shape == plane || hit_shape == circle)
	{
		if (v_dot(ray->dir, obj->n_vector) > 0)
			return (v_mul_val(obj->n_vector, -1));
		return (obj->n_vector);
	}
	else if (hit_shape == sphere)
	{
		if (v_length(\
			v_sub_vec(ray->origin_point, obj->point)) < obj->diameter / 2)
			return (v_mul_val(v_div_val(v_sub_vec(p, obj->point), \
				obj->diameter / 2), -1));
		return (v_div_val(v_sub_vec(p, obj->point), obj->diameter / 2));
	}
	return (_get_n_vector(ray, p, hit_shape, obj));
}

t_rec	get_intersection(t_ray *ray, t_object *obj)
{
	t_rec	rec;

	ft_memset(&rec, 0, sizeof(t_rec));
	rec.hit_obj = obj;
	rec.hit_shape = obj->shape;
	rec.t = hit_objs(ray, obj, &rec);
	rec.frag_point = v_add_vec(ray->origin_point, v_mul_val(ray->dir, rec.t));
	rec.n_vector = get_n_vector(ray, rec.frag_point, rec.hit_shape, obj);
	return (rec);
}

t_rec	find_closestobj(t_ray *ray, t_object **objs)
{
	t_rec	rec;
	t_rec	tmp;
	double	t;
	size_t	i;

	rec.t = -1;
	t = MAXFLOAT;
	i = 0;
	while (objs[i])
	{
		tmp = get_intersection(ray, objs[i]);
		if (tmp.t >= 0 && t > tmp.t)
		{
			rec = tmp;
			t = tmp.t;
		}
		i++;
	}
	return (rec);
}

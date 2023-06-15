/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:44:45 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/15 12:48:20 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	hit_sphere(t_ray *ray, t_object *obj)
{
	t_point	o_sub_c;
	double	determinant;
	double	a;
	double	b;
	double	c;

	o_sub_c = v_sub_vec (ray->origin_point, obj->point);
	a = v_dot (ray->dir, ray->dir);
	b = -2.0 * v_dot (o_sub_c, ray->dir);
	c = v_dot (o_sub_c, o_sub_c) - pow (obj->diameter / 2, 2);
	determinant = b * b - 4 * a * c;
	if (determinant < 0 || (determinant == 0 && -1.0 * b / (2 * a) < 1.0)
		|| (determinant > 0 && (-1.0 * b - sqrt (determinant))/ (2 * a) < 1.0
			&& (-1.0 * b + sqrt (determinant))/ (2 * a) < 1.0))
		return (-1.0);
	else if (determinant == 0)
		return (-1.0 * b / (2 * a));
	else
	{
		if ((-1.0 * b - sqrt (determinant))/ (2 * a) < 1.0)
			return ((-1.0 * b + sqrt (determinant))/ (2 * a));
		else
			return ((-1.0 * b - sqrt (determinant))/ (2 * a));
	}
}

double	hit_plane(t_ray *ray, t_object *obj)
{
	double	numer;
	double	denom;

	numer = v_dot (v_sub_vec (obj->point, ray->origin_point), obj->n_vector);
	denom = v_dot (ray->dir, obj->n_vector);
	if (denom == 0 || (numer / denom) < 1.0)
		return (-1.0);
	else if (numer == 0)
		return (1.0);
	else
		return (numer / denom);
}

double	hit_cylinder(t_ray *ray, t_object *obj)
{
	double	t;

	t = 0.0;
	(void)ray;
	(void)obj;
	return (t);
}

double	hit_con(t_ray *ray, t_object *obj)
{
	double	t;

	t = 0.0;
	(void)ray;
	(void)obj;
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/12 01:38:18 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

uint32_t	get_color(t_data *data, t_rec *rec)
{
	t_color		color;
	t_color		phong_color;
	int			i;

	if (rec->t < 0)
		return (0);
	color = ambient(&(data->a_light), rec);
	phong_color = create_color(0, 0, 0);
	i = -1;
	while (data->lights[++i])
	{
		if (!is_shadow(data->objects, \
			(data->lights)[i], rec->frag_point))
			phong_color = add_color (phong_color, \
			apply_phong (data->lights[i], rec, &(data->camera.ray)));
	}
	color = add_color(color, phong_color);
	return (trans_color_int(color));
}

t_color	apply_phong(t_light *light, t_rec *rec, t_ray *ray)
{
	return (add_color(diffuse(light, rec), specular(light, rec, ray)));
}

t_color	ambient(t_light *a_light, t_rec *rec)
{
	t_color	light_color;

	light_color = ratio_color_val(a_light->color, a_light->light_ratio);
	return (ratio_color_col(rec->hit_color, light_color));
}

t_color	diffuse(t_light *light, t_rec *rec)
{
	t_color	light_color;
	double	diff;

	light_color = ratio_color_val(light->color, light->light_ratio);
	diff = max (v_dot (rec->n_vector,
				v_unit (v_sub_vec (light->point,
						rec->frag_point))), 0.0);
	return (ratio_color_col(rec->hit_color, \
		ratio_color_val(light_color, diff)));
}

t_color	specular(t_light *light, t_rec *rec, t_ray *ray)
{
	t_color	light_color;
	t_ray	reflect_ray;
	t_point	lightdir;
	double	spec;
	int		alpa;

	light_color = ratio_color_val(light->color, light->light_ratio);
	alpa = 2;
	lightdir = v_unit(v_sub_vec(rec->frag_point, light->point));
	reflect_ray.origin_point = rec->frag_point;
	reflect_ray.dir = v_add_vec(lightdir, \
		v_mul_val(v_mul_val(rec->n_vector, v_dot(lightdir, rec->n_vector)), 2));
	spec = max(v_dot(reflect_ray.dir, ray->dir), 0.0);
	return (ratio_color_col(rec->hit_color, \
		ratio_color_val(light_color, pow(spec, alpa))));
}

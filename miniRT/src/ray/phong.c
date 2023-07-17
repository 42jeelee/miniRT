/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/17 19:34:43 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

uint32_t	get_color(t_data *data, t_rec *rec)
{
	t_color		color;
	t_color		phong_color;
	t_list		*now;

	if (rec->t < 0)
		return (0);
	color = ambient(&(data->a_light), rec);
	phong_color = create_color(0, 0, 0);
	now = data->lights;
	while (now)
	{
		if (!is_shadow(data->objects, \
			(t_light *)(now->content), rec->frag_point))
			phong_color = add_color (phong_color, \
			apply_phong ((t_light *)(now->content), rec));
		now = now->next;
	}
	color = add_color(color, phong_color);
	return (trans_color_int(color));
}

t_color	apply_phong(t_light *light, t_rec *rec)
{
	return (diffuse(light, rec));
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

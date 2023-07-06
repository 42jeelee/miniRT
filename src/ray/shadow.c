/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/06 19:10:06 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	is_shadow(t_rec *rec, t_object **obj, t_ray ray_to_light)
{
	int		i;

	i = -1;
	while (obj[++i])
	{
		if (check_block (rec, obj[i], ray_to_light))
			return (1);
	}
	return (0);
}

int	check_block(t_rec *rec, t_object *obj, t_ray ray_to_light)
{
	t_rec	tmp_rec;

	tmp_rec.hit_obj = obj;
	tmp_rec.hit_shape = obj->shape;
	tmp_rec.t = hit_objs (&ray_to_light, obj, &tmp_rec);
	if (tmp_rec.t <= ray_to_light.t && tmp_rec.t >= 0)
		return (1);
	return (0);
}

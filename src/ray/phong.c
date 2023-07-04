/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/04 15:19:41 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	max(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}

u_int32_t	diffuse(t_data *data, t_rec *rec)
{
	double	diff;
	double	r;
	double	g;
	double	b;

	diff = max (v_dot (rec->n_vector,
				v_unit (v_sub_vec (data->lights[0]->point,
						rec->frag_point))), 0.0);
	b = ((rec->color & 255));
	g = (((rec->color >> 8) & 255) % 256);
	r = (((rec->color >> 16) & 255) % 256);
	return (0 | (int)(r * diff) << 16 | (int)(g * diff) << 8 | (int)(b * diff));
}

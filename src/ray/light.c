/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:43:19 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/04 16:49:55 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

u_int32_t	light_color(u_int32_t light, u_int32_t obj_color)
{
	double	r;
	double	g;
	double	b;

	b = (obj_color & 255) & ((light & 255));
	g = (((obj_color >> 8) & 255) % 256) & (((light >> 8) & 255) % 256);
	r = (((obj_color >> 16) & 255) % 256) & (((light >> 16) & 255) % 256);
	return (0 | (int)r << 16 | (int)g << 8 | (int)b);
}

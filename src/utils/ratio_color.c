/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:36:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/08 19:14:47 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	ratio_color_val(t_color old_col, double value)
{
	t_color	color;

	color.r = max_ratio(old_col.r * value);
	color.g = max_ratio(old_col.g * value);
	color.b = max_ratio(old_col.b * value);
	return (color);
}

uint32_t	ratio_color(uint32_t old_col, t_color ratio_col)
{
	return (max_color((int)(((old_col >> 16) & 0xFF) * ratio_col.r)) << 16 | \
	max_color((int)(((old_col >> 8) & 0xFF) * ratio_col.g)) << 8 | \
	max_color((int)((old_col & 0xFF) * ratio_col.b)));
}

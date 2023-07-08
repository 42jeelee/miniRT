/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:52:50 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/08 19:05:58 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

uint32_t	add_color(uint32_t old_col, uint32_t add_col)
{
	return (max_color(((old_col >> 16) & 0xFF) + ((add_col >> 16) & 0xFF)) << 16 | \
		max_color(((old_col >> 8) & 0xFF) + ((add_col >> 8) & 0xFF)) << 8|
		max_color((old_col & 0xFF) + (add_col & 0xFF)));
}

t_color	add_ratio_color(t_color old_col, t_color add_col)
{
	t_color	color;

	color.r = max_ratio(old_col.r + add_col.r);
	color.g = max_ratio(old_col.g + add_col.g);
	color.b = max_ratio(old_col.b + add_col.b);
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:38 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/08 19:30:28 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	create_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	create_ratio_color(uint32_t old_col, double ratio)
{
	t_color	color;

	color = trans_color_struct(old_col);
	color.r = max_ratio((color.r * ratio) / 0xFF);
	color.g = max_ratio((color.g * ratio) / 0xFF);
	color.b = max_ratio((color.b * ratio) / 0xFF);
	return (color);
}

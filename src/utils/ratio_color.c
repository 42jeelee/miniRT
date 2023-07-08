/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:36:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/07 19:54:08 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	ratio_color_val(t_color color, double value)
{
	t_color	ret_color;

	ret_color.r = color.r * value;
	ret_color.g = color.g * value;
	ret_color.b = color.b * value;
	return (ret_color);
}

uint32_t	ratio_color(uint32_t old_color, t_color ratio_color)
{
	t_color	color;

	color = trans_color_struct(old_color);
	color.r *= ratio_color.r;
	color.g *= ratio_color.g;
	color.b *= ratio_color.b;
	return (trans_color_int(color));
}

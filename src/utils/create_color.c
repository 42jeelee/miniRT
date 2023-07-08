/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:38 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/07 19:52:19 by jeelee           ###   ########.fr       */
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

t_color	create_ratio_color(uint32_t old_color, double ratio)
{
	t_color	color;

	color = ratio_color_val(trans_color_struct(old_color), ratio);
	color.r /= 255;
	color.g /= 255;
	color.b /= 255;
	return (color);
}

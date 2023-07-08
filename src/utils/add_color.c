/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:52:50 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/07 19:53:12 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	max_ratio(double value)
{
	if (0.0 > value)
		return (0.0);
	else if (value < 1.0)
		return (value);
	else
		return (1.0);
}

t_color	add_color(t_color color, t_color add_color)
{
	t_color	ret_color;

	ret_color.r = max_ratio(color.r + add_color.r);
	ret_color.g = max_ratio(color.g + add_color.g);
	ret_color.b = max_ratio(color.b + add_color.b);
	return (ret_color);
}


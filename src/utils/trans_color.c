/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:50:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/07 19:51:23 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	trans_color_struct(uint32_t color)
{
	t_color	ret_color;

	ret_color.r = color >> 16 & 0xFF;
	ret_color.g = color >> 8 & 0xFF;
	ret_color.b = color & 0xFF;
	return (ret_color);
}

uint32_t	trans_color_int(t_color old_color)
{
	return (((int)old_color.r << 16) + \
		((int)old_color.g << 8) + (int)old_color.b);
}

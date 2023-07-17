/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:52:50 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:15:39 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

t_color	add_color(t_color old_col, t_color add_col)
{
	t_color	color;

	color.r = max_color(old_col.r + add_col.r);
	color.g = max_color(old_col.g + add_col.g);
	color.b = max_color(old_col.b + add_col.b);
	return (color);
}

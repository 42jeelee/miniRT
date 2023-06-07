/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:01:47 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 23:21:24 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	setting_bg(int type, char *line, t_data *data)
{
	size_t	idx;

	idx = 0;
	if (type == 1)
	{
		idx += parse_decimal(line, &((data->a_light).light_ratio));
		idx += parse_color(line + idx, &((data->a_light).color));
	}
	else if (type == 2)
	{
		idx += parse_coordi(line, &((data->camera).point));
		idx += parse_coordi(line + idx, &((data->camera).n_vector));
		idx += parse_integer(line + idx, &((data->camera).fov));
		if (!(0 <= (data->camera).fov && (data->camera).fov <= 180))
			parse_error_exit("Invalid FOV.", 1);
	}
	while (line[idx] == ' ')
		idx++;
	if (line[idx] && line[idx] != '\n')
		parse_error_exit("Invalid file.", 1);
}

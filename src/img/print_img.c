/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:32:47 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/15 10:57:48 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	print_img(t_data *data)
{
	u_int32_t	color;
	int			i;
	int			j;

	init_img(data);
	init_cam(data, (double)data->params.width / data->params.height);
	i = data->params.height - 1;
	color = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < data->params.width)
		{
			init_dir(&data->camera, (double)j / (data->params.width - 1),
				(double)i / (data->params.height - 1));
			my_mlx_pixel_put (data, j, i, color);
			j++;
		}
		i--;
	}
	mlx_put_image_to_window(data->params.mlx,
		data->params.win, data->params.img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, u_int32_t color)
{
	char	*dst;

	dst = data->params.addr + (y * data->params.line_length + x
			* (data->params.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:32:47 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/04 15:16:52 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	max(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}

u_int32_t	diffuse(t_data *data, t_rec *rec)
{
	double	diff;
	double	r;
	double	g;
	double	b;

	diff = max (v_dot (rec->n_vector,
				v_unit (v_sub_vec (data->lights[0]->point,
						rec->frag_point))), 0.0);
	b = ((rec->color & 255));
	g = (((rec->color >> 8) & 255) % 256);
	r = (((rec->color >> 16) & 255) % 256);
	return (0 | (int)(r * diff) << 16 | (int)(g * diff) << 8 | (int)(b * diff));
}

void	print_img(t_data *data)
{
	u_int32_t	color;
	t_rec		rec;
	int			i;
	int			j;

	set_cposition(data, (double)data->params.width / data->params.height);
	i = data->params.height - 1;
	color = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < data->params.width)
		{
			init_dir(&data->camera, (double)j / (data->params.width - 1),
				(double)i / (data->params.height - 1));
			color = create_trgb (data, &rec, 1);
			color = diffuse (data, &rec);
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

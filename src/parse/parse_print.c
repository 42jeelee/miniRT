/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:15:44 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 21:26:37 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 지울 파일입니다.
#include "../include/minirt.h"

static void	print_point(t_point *point)
{
	printf("[ %f, %f, %f ]", point->x, point->y, point->z);
}

void	print_data(t_data *data)
{
	printf("------------------------------------[data]------------------------------------\n");
	printf("Ambient\t| ratio: [ %f ], color: [ %d ]\n", data->a_light.light_ratio, data->a_light.color);
	printf("camera\t| point: ");
	print_point(&(data->camera.point));
	printf(", n_vector: ");
	print_point(&(data->camera.n_vector));
	printf(", FOV: %d\n", data->camera.fov);
	printf("------------------------------------------------------------------------------\n");
}

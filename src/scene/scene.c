/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:14:24 by jhwang2           #+#    #+#             */
/*   Updated: 2023/06/12 17:25:59 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

void	init_origin_point(t_ray *ray, t_point center)
{
	ray->origin_point = set_vec (center.x, center.y, center.z);
}

void	init_dir(t_ray * ray, t_point orientation)
{
	ray->dir = set_vec (orientation.x, orientation.y, orientation.z);
}

t_point	ray_destination(t_ray *ray, double t)
{
	return (v_add_vec(ray->origin_point, v_mul_val (ray->dir, t)));
}

void	init_cam(t_data *data, t_ray ray, double ratio)
{
	init_origin_point (&data->camera.ray, data->camera.view_point_center);
	init_dir (&data->camera.ray, data->camera.n_vector);
	data->camera.focal_length = 1.0;
	data->camera.ratio = ratio;
	data->camera.view_point_w = 4.0;
	data->camera.view_point_h = data->camera.view_point_w / data->camera.ratio;
	data->camera.view_point_lb = set_vec (data->camera.view_point_center.x - (data->camera.view_point_w / 2),
	data->camera.view_point_center.y - (data->camera.view_point_h / 2),
	data->camera.view_point_center.z - data->camera.focal_length);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:14:24 by jhwang2           #+#    #+#             */
/*   Updated: 2023/06/13 19:55:49 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_origin_point(t_ray *ray, t_point center)
{
	ray->origin_point = set_vec (center.x, center.y, center.z);
}

void	init_dir(t_camera *cam, double u, double v) //이중 whiile문으로 u와 v값을 넣어서 ray의 방향을 바꿈
{
	cam->ray.dir = v_unit (v_sub_vec (v_add_vec (v_add_vec (cam->view_port_lb,
	v_mul_val (cam->horizontal, u)),
	v_mul_val (cam->vertical, v)), cam->ray.origin_point));
}

void	init_cam(t_data *data, double ratio)
{
	t_point	focal;

	init_origin_point (&data->camera.ray, data->camera.center);
	data->camera.focal_length = 1.0;
	data->camera.ratio = ratio;
	data->camera.view_port_w = 4.0;
	data->camera.view_port_h = data->camera.view_port_w / data->camera.ratio;
	focal = set_vec (0, 0, data->camera.focal_length);
	data->camera.horizontal = set_vec (data->camera.view_port_h, 0, 0);
	data->camera.vertical = set_vec (0, data->camera.view_port_h, 0);
	data->camera.view_port_lb = v_sub_vec (v_sub_vec (v_sub_vec (data->camera.ray.origin_point, focal)
		, v_div_val (data->camera.horizontal, 2)), v_div_val (data->camera.vertical, 2));
}

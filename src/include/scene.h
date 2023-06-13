/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:19:46 by jhwang2           #+#    #+#             */
/*   Updated: 2023/06/13 12:31:39 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
 # define SCENE_H

# include "./minirt.h"

typedef struct s_ray //P(t) = A + tb; t_min(뷰포트 시작점)과 t_max고려
{
	t_point	origin_point;//원점
	t_point	dir;//b, 방향과 크기. t가 증가할수록 원점에서 거리가 더 먼 점을 나타냄
}	t_ray;

typedef struct s_camera
{
	t_ray	ray;
	t_point	n_vector; //카메라가 보는 방향
	t_point	center;
	t_point	view_port_lb; //left bottom
	t_point	horizontal;//수평길이
	t_point	vertical;//수직길이
	double	view_port_w; //fov 증가시 같이 증가
	double	view_port_h; //fov 증가시 같이 증가
	double	ratio; //종횡비, mlx의 width / height; view port의 한 길이를 설정했을때 다른 부분을 비율로 정함
	double	focal_length; //뷰포인트까지의 거리, 1.0으로 고정
	int		fov; //시야각
}	t_camera;

void		init_origin_point(t_ray *ray, t_point center);
void		init_dir(t_camera *cam, double u, double v);
void		init_cam(t_data *data, double ratio);

#endif

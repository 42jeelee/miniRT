/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:19:46 by jhwang2           #+#    #+#             */
/*   Updated: 2023/06/13 16:42:55 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
 # define SCENE_H

# include "./minirt.h"

void		init_origin_point(t_ray *ray, t_point center);
void		init_dir(t_camera *cam, double u, double v);
void		init_cam(t_data *data, double ratio);

#endif

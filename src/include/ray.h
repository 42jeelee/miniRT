/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:37:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/14 17:39:06 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "./types.h"

double	hit_sphere(t_ray *ray, t_object *obj);
double	hit_plane(t_ray *ray, t_object *obj);
double	hit_cylinder(t_ray *ray, t_object *obj);
double	hit_con(t_ray *ray, t_object *obj);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:37:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/03 17:11:44 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAY_H
# define RAY_H

# include "./types.h"

u_int32_t	create_trgb(t_data *data, t_rec *rec, int flag);

int			hit_sphere(t_ray *ray, t_object *obj, double value[]);
int			hit_plane(t_ray *ray, t_object *obj, double value[]);
int			hit_cylinder(t_ray *ray, t_object *obj, double value[]);
int			is_front(t_camera *cam, t_object *obj, double t);
int			hit_cone(t_ray *ray, t_object *obj, double value[]);
int			hit_circle(t_ray *ray, t_object *obj, double value[]);
int			r_formula(double a, double b, double c, double value[]);

#endif
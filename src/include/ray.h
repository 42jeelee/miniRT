/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:37:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/15 18:17:04 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "./types.h"

u_int32_t	create_trgb(t_data *data, int flag);

int			hit_sphere(t_ray *ray, t_object *obj, double value[]);
int			hit_plane(t_ray *ray, t_object *obj, double value[]);
int			hit_cylinder(t_ray *ray, t_object *obj, double value[]);
int			hit_con(t_ray *ray, t_object *obj, double value[]);

int			r_formula(double a, double b, double c, double value[]);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_and_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:42:50 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/09 14:06:59 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	v_dot(t_point vec_origin, t_point vec_value)
{
	return ((vec_origin.x * vec_value.x) + (vec_origin.y * vec_value.y) + (vec_origin.z * vec_value.z));
}

t_point	v_cross(t_point vec_origin, t_point vec_value)
{
	t_point	vec_cross;

	vec_cross.x = vec_origin.y * vec_value.z - vec_origin.z * vec_value.y;
	vec_cross.y = vec_origin.x * vec_value.z - vec_origin.z * vec_value.x;
	vec_cross.z = vec_origin.x * vec_value.y - vec_origin.y * vec_value.x;
	return (vec_cross);
}

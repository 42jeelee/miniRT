/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:55:54 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/07 19:50:35 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./types.h"

t_color		trans_color_struct(uint32_t color);
uint32_t	trans_color_int(t_color old_color);

t_color		create_color(double r, double g, double b);
t_color		create_ratio_color(uint32_t old_color, double ratio);

t_color		ratio_color_val(t_color color, double value);
uint32_t	ratio_color(uint32_t old_color, t_color ratio_color);

t_color		add_color(t_color color, t_color add_color);

double		max(double a, double b);

#endif
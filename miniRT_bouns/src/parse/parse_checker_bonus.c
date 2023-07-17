/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:45:41 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:48:33 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

t_object	*new_checker(t_line *line)
{
	t_object	*new_object;

	new_object = (t_object *)malloc(sizeof(t_object));
	if (!new_object)
		parse_perror_exit(1);
	ft_memset(new_object, 0, sizeof(t_object));
	new_object->shape = line->type;
	parse_coordi(line, &(new_object->point));
	parse_decimal(line, &(new_object->diameter));
	parse_color(line, &(new_object->color));
	parse_color(line, &(new_object->sub_color));
	parse_integer(line, &(new_object->num_of_tile[0]));
	parse_integer(line, &(new_object->num_of_tile[1]));
	line->idx = shift_whitespace(line);
	if (!is_comment(line, get_token(line) - line->idx))
	{
		if ((line->line)[line->idx] && (line->line)[line->idx] != '\n')
			parse_error_exit("Invalid file.", line->line, 1);
	}
	return (new_object);
}

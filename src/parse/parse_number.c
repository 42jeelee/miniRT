/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:14:17 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/12 16:14:51 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	parse_integer(char *line, int *integer)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	size = catchs_in_str(line + idx, " ");
	*integer = parse_atoi(line + idx, size);
	idx += size;
	return (idx);
}

int	parse_decimal(char *line, float *decimal)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	size = catchs_in_str(line + idx, " ");
	*decimal = parse_atof(line + idx, size);
	idx += size;
	return (idx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:36:02 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/10 16:15:01 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	catchs_in_str(char *line, char *catchs)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr(catchs, line[i]))
			return (i);
		i++;
	}
	return (i);
}

size_t	shift_whitespace(t_line *line)
{
	size_t	idx;

	idx = line->idx;
	while ((line->line)[idx] && (line->line)[idx] != '\n' && \
		((line->line)[idx] == ' ' || !ft_isprint((line->line)[idx])))
		idx++;
	return (idx);
}

size_t	get_token(t_line *line)
{
	size_t	idx;

	idx = line->idx;
	while ((line->line)[idx] && (line->line)[idx] != '\n' && \
		(line->line)[idx] != ' ' && ft_isprint((line->line)[idx]))
		idx++;
	return (idx);
}

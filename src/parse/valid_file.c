/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:33:05 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/11 16:14:13 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

size_t	count_charnum(char c, char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	valid_filename(char *filename)
{
	size_t	size;

	size = ft_strlen(filename);
	if (!size || count_charnum('.', filename) != 1)
		return (1);
	if (filename[size - 3] != '.' || \
		filename[size - 2] != 'r' || filename[size - 1] != 't')
		return (1);
	return (0);
}

int	valid_file(int ac, char **av)
{
	if (ac == 1)
		return (parse_error("No arguments.", 1));
	else if (ac != 2)
		return (parse_error("Too many arguments.", 1));
	if (valid_filename(av[1]))
		return (parse_error("Invalid filename.", 1));
	return (0);
}

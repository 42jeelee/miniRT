/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:36:02 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 01:51:02 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	parse_atoi(char *str, size_t size)
{
	long long	n;
	int			m;
	size_t		i;

	i = 0;
	m = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (i < size && str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			parse_error_exit("Invaild number.", 1);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (n > 2147483647)
		parse_error_exit("Too big number.", 1);
	return ((int)n * m);
}

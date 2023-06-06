/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:58:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/06 23:02:06 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	parse_file(int ac, char **av, t_data *data)
{
	if (vaild_file(ac, av))
		return (1);
	(void)data;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:58:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 00:53:21 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	parse_file(int ac, char **av, t_data *data)
{
	int	fd;

	if (vaild_file(ac, av))
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		parse_perror_exit();
	close(fd);
	return (0);
}

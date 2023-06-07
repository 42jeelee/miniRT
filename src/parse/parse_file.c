/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:58:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 13:42:30 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// static void	parse_line(char *line, t_data *data)
// {
// 	// line에 대한 파싱작업.
// }

static void	_parsing(int fd, t_data *data)
{
	char		*line;
	t_buffer	bf;

	ft_memset(&bf, 0, sizeof(t_buffer));
	while (1)
	{
		line = parse_gnl(fd, &bf);
		if (!line)
			break ;
		// parse_line(line, data);
		(void)data; // 지워야함
		free(line);
	}
}

int	parse_file(int ac, char **av, t_data *data)
{
	int	fd;

	if (vaild_file(ac, av))
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		parse_perror_exit(1);
	_parsing(fd, data);
	close(fd);
	return (0);
}

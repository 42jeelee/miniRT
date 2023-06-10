/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:58:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/11 02:06:51 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	is_type(char *line, size_t *i)
{
	const char	*types[6] = {"A", "C", "L", "sp", "pl", "cy"};
	size_t		type_idx;
	size_t		size;

	size = 0;
	while (line[*i + size] && line[*i + size] != ' ')
		size++;
	if (size == 0 || size > 2)
		return (0);
	type_idx = -1;
	while (++type_idx < 6)
	{
		if (!ft_strncmp(line + *i, types[type_idx], size))
		{
			*i += size;
			return (type_idx + 1);
		}
	}
	*i += size;
	return (0);
}

static void	parse_line(char *line, t_data *data, int *parsed)
{
	size_t	i;
	int		type;

	i = 0;
	while (line[i] == ' ')
		i++;
	type = is_type(line, &i);
	if (type == 0)
		parse_error_exit("Invalid identifier.", 1);
	else if (type < 3)
		setting_bg(type, line + i, data, parsed);
	else
		setting_object(type, line + i, data);
}

static void	_parsing(int fd, t_data *data)
{
	int			parsed[2];
	char		*line;
	t_buffer	bf;

	parsed[0] = 0;
	parsed[1] = 0;
	ft_memset(&bf, 0, sizeof(t_buffer));
	while (1)
	{
		line = parse_gnl(fd, &bf);
		if (!line || !line[0])
		{
			if (line)
				free(line);
			break ;
		}
		parse_line(line, data, parsed);
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

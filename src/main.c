/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:47:26 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/06 23:01:11 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minirt.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_file(ac, av, &data))
		return (1);
	printf("arg: %s\nexecuting ...\n", av[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:47:26 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 18:03:18 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_data	data;
	if (ac == 1)
	{
		printf("no arguments\n");
		return (1);
	}
	printf("arg: %s\nexecuting ...\n", av[1]);

	init_img (&data);
	print_img (&data);
	mlx_hooks (&data);
	mlx_loop (&data.params.mlx);

	return (0);
}

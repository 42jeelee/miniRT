/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:47:26 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/12 21:38:55 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minirt.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_file(ac, av, &data))
		return (1);
	printf("arg: %s\nexecuting ...\n", av[1]);
	print_data(&data);
	init_img(&data);
	print_img (&data);
	mlx_hooks (&data);
	mlx_loop (data.params.mlx);
	free_data(&data);
	return (0);
}

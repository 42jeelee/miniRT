/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:47:26 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 18:26:57 by jhwang2          ###   ########.fr       */
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
	print_img (&data);
	mlx_hooks (&data);
	mlx_loop (&data.params.mlx);
	return (0);
}

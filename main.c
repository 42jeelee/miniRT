/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:47:26 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/06 20:16:15 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("no arguments\n");
		return (1);
	}
	printf("arg: %s\nexecuting ...\n", av[1]);
	return (0);
}

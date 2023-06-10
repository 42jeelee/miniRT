/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:22:57 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/11 02:15:04 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_perror_exit(int _exitcode)
{
	perror(ANSI_BOL ANSI_BLU "miniRT: " ANSI_RES ANSI_RED);
	printf(ANSI_RES);
	exit(_exitcode);
}

void	parse_error_exit(char *msg, int _exitcode)
{
	printf(ANSI_BOL ANSI_BLU "miniRT: " ANSI_RES);
	printf(ANSI_RED "%s" ANSI_RES "\n", msg);
	exit(_exitcode);
}

int	parse_error(char *msg, int _ret)
{
	printf(ANSI_BOL ANSI_BLU "miniRT: " ANSI_RES);
	printf(ANSI_RED "%s" ANSI_RES "\n", msg);
	return (_ret);
}

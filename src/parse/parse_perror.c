/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:22:57 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/06 21:28:45 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	parse_perror(char *msg, int _ret)
{
	printf(ANSI_BLU "miniRT: " ANSI_RED "%s\n" ANSI_RES, msg);
	return (_ret);
}

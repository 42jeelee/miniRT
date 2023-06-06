/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:14:41 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/06 21:26:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define ANSI_RES "\e[0;0m"
# define ANSI_BOL "\e[0;1m"
# define ANSI_ITA "\e[0;3m"
# define ANSI_BLC "\e[0;30m"
# define ANSI_RED "\e[0;31m"
# define ANSI_GRE "\e[0;32m"
# define ANSI_YEL "\e[0;33m"
# define ANSI_BLU "\e[0;34m"
# define ANSI_MAG "\e[0;35m"
# define ANSI_CYA "\e[0;36m"

int	parse_perror(char *msg, int _ret);

#endif

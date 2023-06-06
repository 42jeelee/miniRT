/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:14:41 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 01:50:18 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define ANSI_RES "\e[0m"
# define ANSI_BOL "\e[1m"
# define ANSI_ITA "\e[3m"
# define ANSI_BLC "\e[30m"
# define ANSI_RED "\e[31m"
# define ANSI_GRE "\e[32m"
# define ANSI_YEL "\e[33m"
# define ANSI_BLU "\e[34m"
# define ANSI_MAG "\e[35m"
# define ANSI_CYA "\e[36m"

int		vaild_file(int ac, char **av);

int		parse_atoi(char *str, size_t size);

int		parse_error(char *msg, int _ret);
void	parse_perror_exit(int _exitcode);
void	parse_error_exit(char *msg, int _exitcode);

#endif

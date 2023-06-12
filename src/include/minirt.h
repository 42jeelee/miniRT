/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:50:25 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/11 14:20:43 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./types.h"
# include "./parse.h"
# include "v_utils.h"
# include "../../libft/libft.h"
# include "../../mlx/mlx.h"

# define WINDOW_X 1920;
# define WINDOW_Y 1080;

int	parse_file(int ac, char **av, t_data *data);

#endif

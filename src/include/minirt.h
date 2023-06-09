/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:50:25 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 18:27:46 by jhwang2          ###   ########.fr       */
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

int		parse_file(int ac, char **av, t_data *data);

int		init_img(t_data *data);
void	print_img(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_hooks(t_data *data);
int		key_hook(int keycode, t_data *data);
#endif

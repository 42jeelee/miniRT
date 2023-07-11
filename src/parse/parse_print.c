/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:15:44 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/12 03:18:58 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 지울 파일입니다.
#include "../include/minirt.h"

static void	print_point(t_point *point)
{
	printf("[ %f, %f, %f ]", point->x, point->y, point->z);
}

static void	print_color(t_color *color)
{
	printf("[ %d, %d, %d ]", color->r, color->g, color->b);
}

static void	print_lights(t_list *llist)
{
	t_list	*now;
	t_light	*light;
	size_t	idx;

	if (!llist)
	{
		printf("lights: (NULL)\n");
		return ;
	}
	idx = 0;
	now = llist;
	while (now)
	{
		light = (t_light *)now->content;
		printf("light[%zu]\t| point: ", idx++);
		print_point(&(light->point));
		printf(", ratio: [ %f ], color: ", light->light_ratio);
		print_color(&(light->color));
		printf("\n");
		now = now->next;
	}
}

static void	print_objects(t_list *objlist)
{
	t_list		*now;
	t_object	*obj;
	size_t		idx;

	if (!objlist)
	{
		printf("objects: (NULL)\n");
		return ;
	}
	idx = 0;
	now = objlist;
	while (now)
	{
		obj = (t_object *)now->content;
		printf("object[%zu]\t| shape: %d, point: ", idx++, obj->shape);
		print_point(&(obj->point));
		printf(", n_vector: ");
		print_point(&(obj->n_vector));
		printf(", diameter: [ %f ], height: [ %f ], color: ", \
			obj->diameter, obj->height);
		print_color(&(obj->color));
		printf("\n");
		now = now->next;
	}
}

void	print_data(t_data *data)
{
	printf("------------------------------------[data]-\
		-----------------------------------\n");
	printf("Ambient\t\t| ratio: [ %f ], color: ", data->a_light.light_ratio);
	print_color(&(data->a_light.color));
	printf("\ncamera\t\t| point: ");
	print_point(&(data->camera.center));
	printf(", n_vector: ");
	print_point(&(data->camera.n_vector));
	printf(", FOV: %d\n", data->camera.fov);
	print_lights(data->lights);
	print_objects(data->objects);
	printf("-------------------------------------------\
		-----------------------------------\n");
}

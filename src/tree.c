/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:17:10 by vklepper          #+#    #+#             */
/*   Updated: 2016/03/08 15:17:14 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	draw_tree(t_data *data, int x, int y, int angle)
{
	int x1;
	int y1;
	int depth_local;

	depth_local = data->depth;
	if (data->depth >= 0)
	{
		x1 = x + cos(angle * (3.14159 / 180)) * data->depth * 5;
		y1 = y + sin(angle * (3.14159 / 180)) * data->depth * 5;
		data->white[2] = 153 - (data->depth_max - data->depth) * 10;
		data->white[1] = 102 + (data->depth_max - data->depth) * 2;
		data->white[0] = 51;
		data->x1 = x1;
		data->y1 = y1;
		draw_line(data, x, y);
		data->depth -= 1;
		draw_tree(data, x1, y1, angle + 20);
		data->depth = depth_local - 1;
		draw_tree(data, x1, y1, angle - 20);
	}
}

void		tree_process(t_data *data)
{
	data->depth_max = data->depth;
	draw_tree(data, (int)data->x2, (int)data->y2, data->angle);
	data->depth = data->depth_max;
}

void		tree(void)
{
	t_data data;

	data_tree(&data);
	global_data(&data);
	init_mlx(&data);
	draw(&data);
}

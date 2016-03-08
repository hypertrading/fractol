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

static void			draw_tree(t_data *data, int x, int y,  int angle, int depth)
{
	int x1;
	int y1;

	if (depth >= 0)
	{
		x1 = x + cos(angle * (M_PI / 180)) * depth * 10;
		y1 = y + cos(angle * (M_PI / 180)) * depth * 10;
		draw_line(data, x, y, x1, y1);
		draw_tree(data, x1, y1, angle + 20, depth - 1);
		draw_tree(data, x1, y1, angle - 20, depth - 1);
	}
}

void	tree_process(t_data *data)
{
	draw_tree(data, (int)data->x, (int)data->y, data->angle, data->depth);
}

void			tree(void)
{
	t_data data;

	data_tree(&data);
	global_data(&data);
	init_mlx(&data);
	draw(&data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:49:13 by vklepper          #+#    #+#             */
/*   Updated: 2016/02/09 12:49:15 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	global_data(t_data *data)
{
	if (!(data->white = (int *)malloc(sizeof(int) * 4)))
		ft_error(-1);
	data->map_x = 500;
	data->map_y = 500;
	data->x = 0;
	data->lock = 0;
	data->iter_max = 50;
	data->zoom = 200;
	data->c = 0;
	data->img_x = (data->x2 - data->x1) * data->zoom;
	data->img_y = (data->y2 - data->y1) * data->zoom;
	data->white[0] = 255;
	data->white[1] = 255;
	data->white[2] = 255;
}

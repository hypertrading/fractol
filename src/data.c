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

void		global_data(t_data *data)
{
	if (!(data->white = (int *)malloc(sizeof(int) * 4)))
		ft_error(-1);
	data->map_x = 500;
	data->map_y = 500;
	data->x = 0;
	data->lock = 0;
	data->iter_max = 50;
	data->zoom = 200;
	data->img_x = (data->x2 - data->x1) * data->zoom;
	data->img_y = (data->y2 - data->y1) * data->zoom;
	data->white[0] = 255;
	data->white[1] = 255;
	data->white[2] = 255;
}
void	data_mandel(t_data *data)
{
	data->fractal = 1;
	data->x1 = -2.1;
	data->x2 = 2.1;
	data->y1 = -1.2;
	data->y2 = 1.2;
	global_data(data);
	init_mlx(data);
	draw(data);
}

void	data_julia(t_data *data)
{	
	data->fractal = 2;
	data->x1 = -1;
	data->x2 = 1;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->c_r = 0.285;
}

void	data_burning(t_data *data)
{
	data->fractal = 3;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 2;
	global_data(data);
	init_mlx(data);
	draw(data);
}
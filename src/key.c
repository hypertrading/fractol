/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:27:45 by vklepper          #+#    #+#             */
/*   Updated: 2016/02/09 13:27:48 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void		zoom(int x, int y, t_data *data)
{
		data->zoom += 20;
		if (x < 250 && y < 250)
		{
			data->x1 -= 0.05; 
			data->y1 -= 0.05;
		}
		if (x > 250 && y < 250)
		{
			data->x1 += 0.05; 
			data->y1 -= 0.05;
		}
		if (x < 250 && y > 250)
		{
			data->y1 += 0.05;
			data->x1 -= 0.05;
		}
		if (x > 250 && y > 250)
		{
			data->y1 += 0.05;
			data->x1 += 0.05;
		}
}

static void		dezoom(int x, int y, t_data *data)
{
		data->zoom -= 20;
		if (x < 250 && y < 250)
		{
			data->x1 += 0.1; 
			data->y1 += 0.1;

		}
		if (x > 250 && y < 250)
		{
			data->x1 -= 0.1; 
			data->y1 += 0.1;

		}
		if (x < 250 && y > 250)
		{
			data->y1 -= 0.1;
			data->x1 += 0.1;

		}
		if (x > 250 && y > 250)
		{
			data->y1 -= 0.1;
			data->x1 -= 0.1;
		}
}

int			mouse_zoom(int click, int x, int y, t_data *data)
{
	if (x < data->map_x && y < data->map_y && x >= 0 && y >= 0)
	{
		if (click == 4)
			zoom(x, y, data);
		if (click == 5)
			dezoom(x, y, data);
	}
	return (0);
}
int 		my_mouse_funct(int x, int y, t_data *data)
{
	if (x < data->map_x && y < data->map_y && x >= 0 && y >= 0 && data->lock == 0)
	{
		data->mouse_x = x;
		data->mouse_y = y;
	}
	return (0);
}

int			my_key_funct(int k, t_data *data)
{
	data->iter_max = k == 69 ? data->iter_max + 20 : data->iter_max + 0;
	data->iter_max = k == 78 ? data->iter_max - 20 : data->iter_max - 0;
	if (k == 49 && data->lock == 0)
		data->lock = 1;
	else 
		data->lock = 0;
	ft_putnbr(k);
	if (k == 53)
		exit(0);
	return (0);
}

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

int 		my_mouse_funct(int click, int x, int y, t_data *data)
{
	int h;
	int i;
	h = 0;
	i = click;
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.adr);
	img_init(data);
	data->x = 0;
	
	if (x < 250 && y < 250)
	{
		data->zoom += 50;
		data->x2 -= 0.1; 
		data->iter_max = 50;
	}
	if (x > 250 && y < 250)
	{
		data->zoom += 50;
		data->x1 += 0.1;
		data->y2 -= 0.1;
		data->iter_max = 50;
	}
	if (x < 250 && y > 250)
	{
		data->zoom += 50;
		data->y1 += 0.1;
		data->iter_max = 50;
	}
	/*data->x2 = x + h;
	data->y1 = y - h;
	data->y2 = y + h;*/
	
	mandel_process(data);
	return (0);
}

int			my_key_funct(int k, t_data *data)
{
	if (k == 69)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img.adr);
		img_init(data);
		data->x = 0;
		data->zoom += 20;
		data->x1 += 0;
		data->x2 -= 0;
		data->y1 += 0;
		data->y2 -= 0.1;
		data->iter_max += 20;
		mandel_process(data);
	}
	if (k == 53)
		exit(0);
	return (0);
}

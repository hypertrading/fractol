/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:30:03 by vklepper          #+#    #+#             */
/*   Updated: 2016/02/09 13:30:04 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	void	mandel_calcul(t_data *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->i = 0;
}

void			mandel_process(t_data *data)
{
	data->x = 0;
	while (data->x < data->img_x)
	{
		data->y = 0;
		while (data->y < data->img_y)
		{
			mandel_calcul(data);
			while ((data->z_r * data->z_r + data->z_i * data->z_i)
			< 4 && data->i < data->iter_max)
			{
				data->tmp = data->z_r;
				data->z_r = data->z_r * data->z_r - data->z_i *
					data->z_i + data->c_r;
				data->z_i = 2 * data->z_i * data->tmp + data->c_i;
				data->i++;
			}
			if (data->i == data->iter_max)
				img_pixel_put(data, data->x, data->y, data->white);
			else
				img_pixel_put(data, data->x, data->y,
					color(data->i, data->iter_max));
			data->y++;
		}
		data->x++;
	}
}

void			mandelbrot(void)
{
	t_data data;

	data_mandel(&data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:37:01 by vklepper          #+#    #+#             */
/*   Updated: 2016/02/05 19:37:03 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mlx(t_data *data)
{
	if ((data->mlx = mlx_init()) == NULL)
		ft_error(-1);
	if ((data->win = mlx_new_window(data->mlx,
		data->map_x, data->map_y, "I am an fractol")) == NULL)
		ft_error(-1);
	img_init(data);
}

void	img_init(t_data *data)
{
	if ((data->img.adr =
		mlx_new_image(data->mlx, data->map_x, data->map_y)) == NULL)
		ft_error(-1);
	if ((data->img.img =
		mlx_get_data_addr(data->img.adr,
			&data->img.bpp, &data->img.sl, &data->img.endian)) == NULL)
		ft_error(-1);
}

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	int	pos;

	if (x < data->map_x && y < data->map_y && x >= 0 && y >= 0)
	{
		pos = (x * data->img.bpp / 8) + (y * data->img.sl);
		data->img.img[pos] = color;
		data->img.img[pos + 1] = color;
		data->img.img[pos + 2] = color;
	}
}

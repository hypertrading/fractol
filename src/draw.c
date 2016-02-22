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
	data->map_x = 500;
	data->map_y = 500;
	if (!(data->mlx = mlx_init()))
		ft_error(-1);
	if (!(data->win = mlx_new_window(data->mlx, data->map_x, data->map_y, "I am a fractol")))
		ft_error(-1);
}

void	img_init(t_data *data)
{
	if (!(data->img.adr = mlx_new_image(data->mlx, data->map_x, data->map_y)))
		ft_error(-1);
	if (!(data->img.img = mlx_get_data_addr(data->img.adr,
			&data->img.bpp, &data->img.sl, &data->img.endian)))
		ft_error(-1);
}

void	img_pixel_put(t_data *data, int x, int y, int *color)
{
	int	pos;

	if (x < data->map_x && y < data->map_y && x >= 0 && y >= 0)
	{
		pos = (x * data->img.bpp / 8) + (y * data->img.sl);
		data->img.img[pos] = color[0];
		data->img.img[pos + 1] = color[1];
		data->img.img[pos + 2] = color[2];
	}
}

void	draw(t_data *data)
{
	mlx_hook(data->win, 2, (1L << 0), my_key_funct, data);
	mlx_mouse_hook(data->win, my_mouse_funct, data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_loop_hook(data->mlx, move, data);
	mlx_loop(data->mlx);
}
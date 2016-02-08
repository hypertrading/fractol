/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:16:22 by vklepper          #+#    #+#             */
/*   Updated: 2016/02/04 19:16:24 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putendl("Aie ! Il semble que les arguments rentrés sont erronés.");
	if (i == 2)
		ft_putendl("error in mandelbrot()");
	if (i == -1)
		ft_putendl("error mlx_init");
	exit(1);
}

int			my_key_funct(int k)
{
	if (k == 53)
		exit(0);
	return (0);
}

void	img_init(t_data *data)
{
	if ((data->img.adr = mlx_new_image(data->mlx, data->map_x, data->map_y)) == NULL)
		ft_error(-1);
	if ((data->img.img = mlx_get_data_addr(data->img.adr, &data->img.bpp, &data->img.sl, &data->img.endian)) == NULL)
		ft_error(-1);
}

int 	ft_mandelbrot(void)
{
	t_data  data;
	int x;
	int y;
	//int tmp;

	data.map_x = 500;
	data.map_y = 500;
	if ((data.mlx = mlx_init()) == NULL)
		ft_error(-1);
	if ((data.win = mlx_new_window(data.mlx, data.map_x, data.map_y, "I am an fractol")) == NULL)
	img_init(&data);
	/*data.x1 = -2.1;
	data.x2 = 0.6;
	data.y1 = -1.2;
	data.y2 = 1.2;
	data.zoom = 100;
	data.iter_max = 50;
	data.img_x = (data.x2 - data.x1) * data.zoom;
	data.img_y = (data.y2 - data.y1) * data.zoom;
	x = 0;
	while (x < data.img_x)
	{
		y = 0;
		while (y < data.img_y)
		{
			data.c_r = x / data.zoom + data.x1;
			data.c_i = y / data.zoom + data.y1;
			data.z_r = 0;
			data.z_i = 0;
			data.i = 0;

			while ((data.z_r * data.z_r + data.z_i * data.z_i) < 4 && data.i < data.iter_max)
			{
				tmp = data.z_r;
				data.z_r = data.z_r * data.z_r - data.z_i * data.z_i + data.c_r;
            	data.z_i = 2 * data.z_i * tmp + data.c_i;
           		data.z_i = 2 * data.z_i * tmp + data.c_i;
            	data.i++;
            }
            if (data.i == data.iter_max)
            {
            	img_pixel_put(&data, x, y);
            }
            y++;
		}
		x++;
	}*/
	x = 100;
	y = 100;
	img_pixel_put(&data, x, y);
	//mlx_put_image_to_window(data.mlx, data.win, data.img.adr, 0, 0);
	mlx_hook(data.win, 2, 1, my_key_funct, 0);
	mlx_loop(data.mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	char *mandelbrot;

	mandelbrot = "mandelbrot";
	if (argc != 2)
		ft_error(1);
	if (ft_strcmp(argv[1], mandelbrot) == 0)
	{
		if (ft_mandelbrot() != 0)
			ft_error(2);
	}
	return (0);
}
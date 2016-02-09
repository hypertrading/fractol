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

int			my_key_funct(int k, t_data *data)
{
	if (k == 69)
	{
		data->zoom += 10;
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img.adr);
		img_init(data);
		mandel_process(data);
	}
	if (k == 53)
		exit(0);
	return (0);
}

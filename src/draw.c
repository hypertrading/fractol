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

void	img_pixel_put(t_data *data, int x, int y)
{
	int	pos;

	if (x < data->map_x && y < data->map_y && x >= 0 && y >= 0)
	{
		pos = (x * data->img.bpp / 8) + (y * data->img.sl);
		data->img.img[pos] = 0;
		data->img.img[pos + 1] = 0;
		data->img.img[pos + 2] = 0;
	}
}
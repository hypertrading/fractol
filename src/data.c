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

void	data_mandel(t_data *data)
{
	data->x = 0;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->iter_max = 50;
	data->img_x = (data->x2 - data->x1) * data->zoom;
	data->img_y = (data->y2 - data->y1) * data->zoom;
}

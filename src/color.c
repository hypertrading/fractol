/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:11:52 by vklepper          #+#    #+#             */
/*   Updated: 2016/02/09 17:11:54 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	*color(int i, int iter_max, t_data *data)
{
	static int	rgb[3];

	if (data->c == 0)
	{
		rgb[0] = i * 100 / iter_max + 155;
		rgb[1] = i * 220 / iter_max + 20;
		rgb[2] = i * 160 / iter_max + 10;
	}
	if (data->c == 1)
	{
		rgb[0] = i * 50 / iter_max + 50;
		rgb[1] = i * 110 / iter_max + 10;
		rgb[2] = i * 80 / iter_max + 50;
	}
	if (data->c == 2)
	{
		rgb[0] = i * 200 / iter_max + 15;
		rgb[1] = i * 50 / iter_max + 20;
		rgb[2] = i * 75 / iter_max + 10;
	}
	return (rgb);
}

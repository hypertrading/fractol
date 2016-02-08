/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:15:51 by vklepper          #+#    #+#             */
/*   Updated: 2016/02/04 19:15:55 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "stdlib.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct		s_img
{
	void			*adr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				map_x;
	int				map_y;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			zoom;
	float 			iter_max;
	float			img_x;
	float			img_y;
	float			c_r;
	float			c_i;
	float 			z_r;
	float 			z_i;
	float 			i;
	t_img			img;
}					t_data;

void	img_pixel_put(t_data *data, int x, int y);

#endif

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

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_error(1);
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mandelbrot();
	else if (ft_strcmp(argv[1], "julia") == 0)
		julia();
	else if (ft_strcmp(argv[1], "burningship") == 0)
		burningship();
	else if (ft_strcmp(argv[1], "tree") == 0)
		tree();
	return (0);
}

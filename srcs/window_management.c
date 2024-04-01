/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:08:37 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/30 16:00:43 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//close the window when we press ESC
int	close_window(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	return (0);
}

//or when we click on the red cross at the top left corner
int	close_red_cross(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}

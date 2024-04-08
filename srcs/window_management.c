/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:08:37 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/08 17:32:53 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//close the window when we press ESC
//and remap the drawing after touched one of the 4 arrows
//or we change the color iteration by pressing TAB/SHIFT
int	manage_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	else if (keycode == ARROW_LEFT)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_RIGHT)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keycode == ARROW_UP)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_DOWN)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keycode == SHIFT)
		fractal->max_iteration += 1000;
	else if (keycode == TAB)
		fractal->max_iteration -= 500;
	draw_fractal(fractal);
	return (0);
}

//with the mouse, we want to zoom where the cursor is located
//x and y, in the prototype, are the coordinates of the mouse in the window. 
//we want to map them to convert the same coordinates for the cartesian plan
//we stock thoses values in our structure to use them after
//then when we will draw the fractal, the new values will be set
int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == SCROLLDOWN)
	{
		fractal->zoom *= 0.8;
	}
	else if (keycode == SCROLLUP)
	{
		fractal->zoom *= 1.2;
	}
	mlx_clear_window(fractal->mlx, fractal->win);
	draw_fractal(fractal);
	return (0);
}

//this function is useful to close the window and the programm
//when we click on the red cross at the top left corner of the window
int	close_red_cross(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}

/*int	print_keycode(int keycode, t_fractal *fractal)
{
	int	x;

	printf("%i\n", keycode);
	x = fractal->endian;
	return (0);
}*/

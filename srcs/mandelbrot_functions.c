/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:21:07 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/01 14:05:54 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//we want to draw the mandelbrot for each pixel in the cartesian plan
//WATCH OUT: each time you work with your coordinates, (x, y) has to be double
//the conversion pixel are used to be able to correctly see our mandelbrot
//if we reach the 1000th iteration, we consider that the point (x, y) is bounded
//Which means that the point (x, y) is located in the mandelbrot set
//otherwise, it isn't and we print the pixel with a different color
int	draw_mandelbrot(double x, double y, t_fractal *fractal)
{
	double	xtmp;
	int		i;
	int		max_iteration;

	x = x / WIDTH * 4.0 - 2.0;//pixel conversion to see the mandelbrot
	y = y / HEIGHT * 4.0 - 2.0;//pixel conversion to see the mandelbrot
	i = 0;
	max_iteration = 1000;
	fractal->zx = 0;
	fractal->zy = 0;
	while ((fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4)
		&& (i < max_iteration))
	{
		xtmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + x;
		fractal->zy = 2 * fractal->zx * fractal->zy + y;
		fractal->zx = xtmp;
		i++;
	}
	if (i == max_iteration)
		return (WHITE);
	else
		return (BLACK);
}

//we draw the graphic for each pixel in our window
//when it's done, we put our image on the window
void	draw_fractal(t_fractal *fractal)
{
	double	x;
	double	y;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = draw_mandelbrot(x, y, fractal);
			my_mlx_pixel_put(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

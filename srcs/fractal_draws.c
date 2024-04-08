/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_draws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:07:59 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/08 17:28:42 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//we want to draw the mandelbrot for each pixel in the cartesian plan
//WATCH OUT: each time we work with your coordinates, (x, y) has to be double
//the conversion pixel are used to be able to correctly see our mandelbrot
//we print the color of the pixel depending on if we reach the 1000th iteration
//if we reach the 1000th iteration, we consider that the point (x, y) is bounded
//Which means that the point (x, y) is located in the mandelbrot set
//otherwise, it isn't and we print the pixel with a different color
int	draw_mandelbrot(double x, double y, t_fractal *fractal)
{
	double	xtmp;
	int		i;

	x = map(x, ABSCISSA_MIN, ABSCISSA_MAX, WIDTH);
	y = map(y, ORDINATE_MIN, ORDINATE_MAX, HEIGHT);
	fractal->cx = x * fractal->zoom + fractal->shift_x;
	fractal->cy = y * fractal->zoom + fractal->shift_y;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	i = 0;
	while ((fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4.0)
		&& (i < fractal->max_iteration))
	{
		xtmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy \
		+ fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = xtmp;
		i++;
	}
	return (color_fractal(i));
}

int	draw_julia(double x, double y, t_fractal *fractal)
{
	double	zx;
	double	zy;
	int		i;
	double	xtmp;

	zx = map(x, -2, 2, WIDTH);
	zy = map(y, -2, 2, HEIGHT);
	zx = zx * fractal->zoom + fractal->shift_x;
	zy = zy * fractal->zoom + fractal->shift_y;
	i = 0;
	while ((zx * zx + zy * zy) < 4 && i < fractal->max_iteration)
	{
		xtmp = zx * zx - zy * zy + fractal->julia_x;
		zy = 2 * zx * zy + fractal->julia_y;
		zx = xtmp;
		i++;
	}
	return (color_fractal(i));
}

int	draw_tricorn(double x, double y, t_fractal *fractal)
{
	double	xtmp;
	int		i;

	x = map(x, -2, 2, WIDTH);
	y = map(y, -2, 2, HEIGHT);
	x = x * fractal->zoom + fractal->shift_x;
	y = y * fractal->zoom + fractal->shift_y;
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	while ((fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4.0)
		&& (i < fractal->max_iteration))
	{
		xtmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + x;
		fractal->zy = -2 * fractal->zx * fractal->zy + y;
		fractal->zx = xtmp;
		i++;
	}
	return (color_fractal(i));
}

int	draw_burningship(double x, double y, t_fractal *fractal)
{
	double	xtmp;
	int		i;

	x = map(x, -2, 2, WIDTH);
	y = map(y, -2, 2, HEIGHT);
	x = x * fractal->zoom + fractal->shift_x;
	y = y * fractal->zoom + fractal->shift_y;
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	while ((fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4.0)
		&& (i < fractal->max_iteration))
	{
		xtmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + x;
		fractal->zy = fabs(2 * fractal->zx * fractal->zy) + y;
		fractal->zx = xtmp;
		i++;
	}
	return (color_fractal(i));
}

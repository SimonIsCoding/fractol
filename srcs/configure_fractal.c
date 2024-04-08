/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:21:07 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/08 17:29:25 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//This function converts a RGB color into an integer
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//useful to color the fractal and to show the depth of the fractal
int	color_fractal(int i)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = (i * 10) % 255;
	g = (i * 7) % 255;
	b = (i * 5) % 255;
	color = create_trgb(0, r, g, b);
	return (color);
}

//as long as the point (0, 0) is located at the top left corner of the window
//we have to map it to see it in the middle, to see it in a cartesian plan
double	map(double unscaled_nb, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_nb - old_min) \
			/ (old_max - old_min) + new_min);
}

//we draw the graphic for each pixel in our window
//when it's done, we put our image on the window
void	draw_fractal(t_fractal *fractal)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(fractal->name, "julia", 5))
				color = draw_julia(x, y, fractal);
			else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
				color = draw_mandelbrot(x, y, fractal);
			else if (!ft_strncmp(fractal->name, "tricorn", 7))
				color = draw_tricorn(x, y, fractal);
			else if (!ft_strncmp(fractal->name, "burning_ship", 12))
				color = draw_burningship(x, y, fractal);
			my_mlx_pixel_put(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

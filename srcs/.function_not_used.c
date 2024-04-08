/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .function_not_used.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:24:49 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/08 17:27:28 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//this was a bit helpful : https://stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c?newreg=77039ff894564d668146b5fa147dd605
typedef struct	cartesian_plan
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}				c_plan;

/*void	mapping_values(int x, int y, t_fractal *fractal)
{
	x = map(x, -2, 2, WIDTH);
	y = map(y, -2, 2, HEIGHT);
	fractal->cx = x * fractal->zoom + fractal->shift_x;
	fractal->cy = y * fractal->zoom + fractal->shift_y;
}*/

/*int	draw_burningship(double x, double y, t_fractal *fractal)
{
	double	zx;
	double	zy;
	int		i;
	double	xtmp;

	zx = map(x, -2, 2, WIDTH);// * fractal->zoom + fractal->shift_x;
	zy = map(y, -2, 2, HEIGHT);// * fractal->zoom + fractal->shift_y;
	x = map(x, -2, 2, WIDTH);
	y = map(y, -2, 2, HEIGHT);
	i = 0;
	while ((zx * zx + zy * zy) < 4 && i < fractal->max_iteration)
	{
		xtmp = zx * zx - zy * zy + x;
		zy = fabs(2 * zx * zy) + y;
		zx = xtmp;
		i++;
	}
	return (color_fractal(i));
}*/

/*int	draw_tricorn(double x, double y, t_fractal *fractal)
{
	double	zx;
	double	zy;
	int		i;
	double	xtmp;

	zx = map(x, -2, 2, WIDTH);// * fractal->zoom + fractal->shift_x;
	zy = map(y, -2, 2, HEIGHT);// * fractal->zoom + fractal->shift_y;
	x = map(x, -2, 2, WIDTH);
	y = map(y, -2, 2, HEIGHT);
	i = 0;
	while ((zx * zx + zy * zy) < 4 && i < fractal->max_iteration)
	{
		xtmp = zx * zx - zy * zy + x;
		zy = -2 * zx * zy + y;
		zx = xtmp;
		i++;
	}
	return (color_fractal(i));
}*/

/*int	draw_mandelbrot(double x, double y, t_fractal *fractal)
{
	double	zx;
	double	zy;
	int		i;
	double	xtmp;

	zx = map(x, -2, 2, WIDTH);// * fractal->zoom + fractal->shift_x;
	zy = map(y, -2, 2, HEIGHT);// * fractal->zoom + fractal->shift_y;
	x = map(x, -2.0, 2.0, WIDTH);
	y = map(y, -2.0, 2.0, HEIGHT);
	x = x * fractal->zoom + fractal->shift_x;
	y = y * fractal->zoom + fractal->shift_y;
	i = 0;
	while ((zx * zx + zy * zy) < 4 && i < fractal->max_iteration)
	{
		xtmp = zx * zx - zy * zy + x;
		zy = 2 * zx * zy + x;
		zx = xtmp;
		i++;
	}
	return (color_fractal(i));
}*/

//we use the coordinates of the mouse to rescale them for our cartesian plan
void	mapping_mouse_coordinates(double x, double y, t_fractal *fractal)
{
	fractal->mouse_x = x / (WIDTH / (ABSCISSA_MAX - ABSCISSA_MIN))\
					   + ABSCISSA_MIN;
	fractal->mouse_y = y / (WIDTH / (ORDINATE_MAX - ORDINATE_MIN))\
					   + ORDINATE_MIN;
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyZoom(t_fractal *fractal)
{
	double	interpolation;
	double	abscissa_min;
	double	abscissa_max;
	double	ordinate_min;
	double	ordinate_max;

//	interpolation = 1.0 / fractal->zoom;
	interpolation = fractal->zoom;
	abscissa_min = interpolate(fractal->mouse_x, ABSCISSA_MIN, interpolation);
	ordinate_min = interpolate(fractal->mouse_y, ORDINATE_MIN, interpolation);
	abscissa_max = interpolate(fractal->mouse_x, ABSCISSA_MAX, interpolation);
	ordinate_max = interpolate(fractal->mouse_y, ORDINATE_MAX, interpolation);
	printf("voici les 4 maxima de notre nouvelle fenetre:\n\t%f\n%f\t\t%f\n\t%f\n\n", abscissa_min, ordinate_max, abscissa_max, ordinate_min);
}



/*	int	abs_len;
	int	ord_len;

	abs_len = fractal->plan.max_x - fractal->plan.min_x;
	ord_len = fractal->plan.max_y - fractal->plan.min_y;

	if (keycode == SCROLLDOWN)
	{
		fractal->plan.min_x -= ((abs_len / fractal->zoom) - abs_len) * x;
		fractal->plan.max_x += ((abs_len / fractal->zoom) - abs_len) * (1 - x);
		fractal->plan.min_y -= ((ord_len / fractal->zoom) - ord_len) * y;
		fractal->plan.max_y += ((ord_len / fractal->zoom) - ord_len) * (1 - y);
	}
	else if (keycode == SCROLLUP)
	{
		fractal->plan.min_x -= ((abs_len * fractal->zoom) - abs_len) * x;
		fractal->plan.max_x += ((abs_len * fractal->zoom) - abs_len) * (1 - x);
		fractal->plan.min_y -= ((ord_len * fractal->zoom) - ord_len) * y;
		fractal->plan.max_y += ((ord_len * fractal->zoom) - ord_len) * (1 - y);
	}
*/	else
	{
		printf("coordinates of the mouse in pixel: (%f, %f)\n", (double)x, (double)y);
		mapping_mouse_coordinates(x, y, fractal);
		printf("coordinates of the mouse - rescaled: (%f, %f)\n", fractal->mouse_x, fractal->mouse_y); 
	}


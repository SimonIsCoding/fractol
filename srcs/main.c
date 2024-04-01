/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:35:44 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/01 14:05:01 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//open a window with our drawing
//we firstly need to initialize our values to be able to see the final drawing
//then we create condition to show the correct drawing
//the hook functions are here to exit from the window when the user wants
void	open_window(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, TITLE_WIN);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	draw_fractal(fractal);
	mlx_key_hook(fractal->win, close_window, &fractal->mlx);
	mlx_hook(fractal->win, ON_DESTROY, 0, close_red_cross, &fractal->mlx);
	mlx_loop(fractal->mlx);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	error_management(argc, argv);
	//prompts corrects
	open_window(fractal);
	return (0);
}

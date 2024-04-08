/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:35:44 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/08 17:32:29 by simarcha         ###   ########.fr       */
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

//we want to initialise the value of our structure to work correctly with the 
//drawing
void	fractal_init(int argc, char **argv, t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->max_iteration = 1000;
	fractal->name = argv[1];
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	if (argc == 4)
	{
		fractal->julia_x = ft_atod(argv[2]);
		fractal->julia_y = ft_atod(argv[3]);
	}
	else
	{
		fractal->julia_x = 0.4;
		fractal->julia_y = 0.4;
	}
}

//open a window with our drawing
//we firstly need to initialize our values to be able to see the final drawing
//then we create condition to show the correct drawing
//the hook functions are here to exit from the window when the user wants
void	manage_window(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	draw_fractal(fractal);
	mlx_hook(fractal->win, 4, 0, mouse_hook, fractal);
	mlx_key_hook(fractal->win, manage_key, &fractal->mlx);
	mlx_hook(fractal->win, ON_DESTROY, 0, close_red_cross, &fractal->mlx);
	mlx_loop(fractal->mlx);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	error_management(argc, argv);
	fractal_init(argc, argv, &fractal);
	manage_window(&fractal);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:57:22 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/08 21:30:30 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH				500//Width of the windows = x axis
# define HEIGHT				500//Height of the windows = y axis
# define ABSCISSA_MIN		-2//the beginning of our cartesian plan on x axis
# define ABSCISSA_MAX		2//the end of our cartesian plan on x axis
# define ORDINATE_MIN		-2//the beginning of our cartesian plan on y axis
# define ORDINATE_MAX		2//the end of our cartesian plan on y axis
# define ESC				53//keycode for ESC on the keyboard
# define ARROW_LEFT			123//keycode for the left arrow on the keyboard
# define ARROW_RIGHT		124//keycode for the right arrow on the keyboard
# define ARROW_DOWN			125//keycode for the down arrow on the keyboard
# define ARROW_UP			126//keycode for the up arrow on the keyboard
# define SCROLLUP			4//keycode for the frontward mouse scroll 
# define SCROLLDOWN			5//keycode for the backward mouse scroll
# define SHIFT				257//keycode for the SHIFT arrow on the keyboard
# define TAB				48//keycode for the TAB on the keyboard
# define ERROR_MSG_1		"Please write a correct input\n"
# define ERROR_MSG_2		"with (-2; -2) ≤ (x; y) ≤ (2; 2)\n"
# define ERROR_MSG_3		"Example: ./fractol julia 0.3 -0.56\n"
# define ERROR_MSG_4		"Example: ./fractol mandelbrot\n"
# define ERROR_MSG_5		"Example: ./fractol tricorn\n"
# define ERROR_MSG_6		"Example: ./fractol burning_ship\n"

# include <stdlib.h>//malloc, free, exit
# include "../mlx/mlx.h"
# include <math.h>//fabs function
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/ft_printf/libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;//the name of the fractal that we are showing
	double	zx;//real value for the mandelbrot n-th iteration - ∈ ℝ 
	double	zy;//complex value for the mandelbrot n-th iteration - ∈ ℂ 
	double	cx;//mandelbrot constant in ℝ - abscissa axis
	double	cy;//mandelbrot constant in ℂ - ordinate axis
	double	zoom;//if we zoom with the mouse, we have to rescale the drawing
	double	shift_x;//if we move with the arrow, we move the drawing vertically
	double	shift_y;//if we move with the arrow, we move the drawing horizontaly
	double	max_iteration;//the more iteration there is, the clearer it is
	double	julia_x;//input by the user to draw a specific julia set <=> argv[2]
	double	julia_y;//input by the user to draw a specific julia set <=> argv[3]
}				t_fractal;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

//characters_into_double.c
double	ft_atod(const char *str);

//error_management.c
void	error_management(int argc, char **argv);

//window_management.c
int		manage_key(int keycode, t_fractal *fractal);
int		close_red_cross(t_fractal *vars);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);
//int	print_keycode(int keycode, t_fractal *fractal);

//configure_fractal.c
int		create_trgb(int t, int r, int g, int b);
int		color_fractal(int i);
double	map(double unscaled_nb, double new_min, double new_max, double old_max);
void	mapping_values(int x, int y, t_fractal *fractal);
void	draw_fractal(t_fractal *fractal);

//fractal_draws.c
int		draw_mandelbrot(double x, double y, t_fractal *fractal);
int		draw_julia(double x, double y, t_fractal *fractal);
int		draw_tricorn(double x, double y, t_fractal *fractal);
int		draw_burningship(double x, double y, t_fractal *fractal);

//aux.c || main.c
void	print_error(char *str);//not used
void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
void	fractal_init(int argc, char **argv, t_fractal *fractal);

#endif

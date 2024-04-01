/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:57:22 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/01 14:07:18 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH				1000//x
# define HEIGHT				1000//y
# define TITLE_WIN			"Fractol"
# define MAX_COLOR_RANGE	16777215
# define MLX_ERROR			1
# define ESC				53
# define SPACE				49
# define WHITE				0xFFFFFF
# define BLACK				0x000000
# define PSYCHEDELIC_RED	0xFF0000
# define PSYCHEDELIC_GREEN	0x00FF00
# define PSYCHEDELIC_BLUE	0x0000FF
# define PSYCHEDELIC_YELLOW	0xFFFF00
# define PSYCHEDELIC_PURPLE	0xFF00FF
# define PSYCHEDELIC_CYAN	0x00FFFF
# define PSYCHEDELIC_ORANGE	0xFFA500
# define PSYCHEDELIC_PINK	0xFFC0CB
# define PSYCHEDELIC_LIME	0x00FF00
# define PSYCHEDELIC_TEAL	0x008080
# define PSYCHEDELIC_AQUA	0x00FFFF
# define PSYCHEDELIC_MAGENTA	0xFF00FF
# define PSYCHEDELIC_INDIGO	0x4B0082
# define PSYCHEDELIC_LAVENDER	0xE6E6FA
# define PSYCHEDELIC_MAROON	0x800000
# define PSYCHEDELIC_NAVY	0x000080
# define PSYCHEDELIC_OLIVE	0x808000
# define PSYCHEDELIC_SILVER	0xC0C0C0
# define PSYCHEDELIC_TEAL	0x008080
# define PSYCHEDELIC_SKY_BLUE	0x87CEEB

# include <unistd.h>//close, write
# include <stdlib.h>//malloc, free, exit
# include <stdio.h>//perror
# include <fcntl.h>//open
# include <string.h>//strerror
# include "../mlx/mlx.h"
# include <math.h>
# include "../utils/libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zx;//real value for the n-th iteration - ∈ ℝ 
	double	zy;//complex value for the n-th iteration - ∈ ℂ 
	double	cx;//mandelbrot constant in ℝ - abscissa axis
	double	cy;//mandelbrot constant in ℂ - ordinate axis
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
int		close_window(int keycode, t_fractal *vars);
int		close_red_cross(t_fractal *vars);

//mandelbrot_functions.c
int		draw_mandelbrot(double x, double y, t_fractal *fractal);
void	draw_fractal(t_fractal *fractal);

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
#endif

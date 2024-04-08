/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibX_exercises.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:48:07 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/29 10:55:57 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_square(t_data img, int color)
{
	int		i;
	int		j;

	i = 5;
	while (i < 750)
	{
		j = 5;
		while (j < 750)
		{
			my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		i++;
	}
}

int	get_opposite(int color)
{
	return (MAX_COLOR_RANGE - color);
}

/*int	add_shade(int color)
{
	char	*str;

	str = (char )color;
	printf("%s\n", str);
	return (0);
}*/

//on veut changer la couleur au fur et a mesure que l'on dessine des pixels
/*void	create_gradient(int color)
{
	if (color < MAX_COLOR_RANGE)
		color++;
	else if (color == MAX_COLOR_RANGE)
}*/

void	draw_circle(t_data img, int cx, int cy, int radius)
{
  int d, y, x, color;
 
  d = 3 - (2 * radius);
  x = 0;
  y = radius;
  color = 0x0046BEF9;
 
  while (y >= x)
  {
	my_mlx_pixel_put(&img, cx + x, cy + y, color);
	my_mlx_pixel_put(&img, cx + y, cy + x, color);
	my_mlx_pixel_put(&img, cx - x, cy + y, color);
	my_mlx_pixel_put(&img, cx - y, cy + x, color);
	my_mlx_pixel_put(&img, cx + x, cy - y, color);
	my_mlx_pixel_put(&img, cx + y, cy - x, color);
	my_mlx_pixel_put(&img, cx - x, cy - y, color);
	my_mlx_pixel_put(&img, cx - y, cy - x, color);
    if (d < 0)
      d = d + (4 * x) + 6;
    else
	{
      d = d + 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
}

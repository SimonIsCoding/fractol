/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .exo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:38:32 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/31 15:42:14 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	rescale_axis(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

int main(void)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		printf("%d -> %f\n", i, rescale_axis((double)i, -2, +2, 0, 799));
		i++;
	}
}

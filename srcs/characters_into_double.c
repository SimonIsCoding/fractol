/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_into_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:08:46 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/09 12:54:04 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//we want a function that checks if the inputs written is a number written like
//0.0
//for this we need a function that converts the string from the argv into double
static double	power_of_ten(int exp)
{
	double	result;

	result = 1.0;
	while (exp > 0)
	{
		result *= 10.0;
		exp--;
	}
	return (result);
}

static double	atod_helper(const char *str, double frac, int dcm, double res)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			frac = frac * 10.0 + (str[i] - '0');
			dcm++;
			i++;
		}
	}
	res += frac / power_of_ten(dcm);
	return (res);
}

double	ft_atod(const char *str)
{
	double	fraction;
	int		sign;
	double	result;
	int		decimal;
	int		i;

	result = 0.0;
	decimal = 0;
	sign = 1;
	i = 0;
	fraction = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && sign == 1)
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	return (atod_helper(&str[i], fraction, decimal, result) * sign);
}

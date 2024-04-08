/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:19:28 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/06 11:57:55 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//the range for the julia's input has to be: -2 ≤ x ≤ 2
static void	check_range(char **argv)
{
	if ((ft_atod(argv[2]) > 2 || ft_atod(argv[2]) < -2)
		|| (ft_atod(argv[3]) > 2 || ft_atod(argv[3]) < -2))
	{
		ft_printf("%s%s%s%s%s", \
			ERROR_MSG_1, ERROR_MSG_3, ERROR_MSG_4, ERROR_MSG_5, ERROR_MSG_6);
		exit(1);
	}
}

//if there is characters different from the double type number => we give error
static void	check_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 2;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((ft_isdigit(argv[i][j]) == 1) || (argv[i][j] == '.')
				|| (argv[i][j] == '-') || (argv[i][j] == '+')
				|| (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))))
			{
				ft_printf("%s%s%s%s%s", ERROR_MSG_1 \
						, ERROR_MSG_3, ERROR_MSG_4, ERROR_MSG_5, ERROR_MSG_6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

//if there is more than 6 digits after the comma in our double number
//and if the unit number is 2
//all of the decimals digits have to be 0. If not => Error;
static void	check_decimals(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][++j])
		{
			if (j > 0 && argv[i][j] == '.' && argv[i][j - 1] == '2')
			{
				j++;
				while (argv[i][j] == '0')
					j++;
				if (j < (int)ft_strlen(argv[i]) && argv[i][j] != '0')
				{
					ft_printf("%s%s%s%s%s", ERROR_MSG_1, ERROR_MSG_2, \
							ERROR_MSG_3, ERROR_MSG_4, ERROR_MSG_5, ERROR_MSG_6);
					exit(1);
				}
			}
		}
	}
}

void	error_management(int argc, char **argv)
{
	if ((argc == 2 && !(ft_strncmp(argv[1], "mandelbrot", 10)))
		|| (argc == 2 && !(ft_strncmp(argv[1], "julia", 5)))
		|| (argc == 2 && !(ft_strncmp(argv[1], "tricorn", 7)))
		|| (argc == 2 && !(ft_strncmp(argv[1], "burning_ship", 12))))
	{
		if (argc == 2 && !(ft_strncmp(argv[1], "julia", 5)))
		{
			ft_putstr_fd("You can also follow this example :)\n", 1);
			ft_putstr_fd("Example: ./fractol julia 0.3 -0.56\n", 1);
		}
		return ;
	}
	else if (argc == 4 && !(ft_strncmp(argv[1], "julia", 5)))
	{
		check_range(argv);
		check_numbers(argc, argv);
		check_decimals(argc, argv);
		return ;
	}
	else
	{
		ft_printf("%s%s%s%s%s", \
			ERROR_MSG_1, ERROR_MSG_3, ERROR_MSG_4, ERROR_MSG_5, ERROR_MSG_6);
		exit(1);
	}
}

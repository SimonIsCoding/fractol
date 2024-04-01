/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:19:28 by simarcha          #+#    #+#             */
/*   Updated: 2024/04/01 13:35:44 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//the range for the julia's input has to be: -2 ≤ x ≤ 2
static void	check_range(char **argv)
{
	if ((ft_atod(argv[2]) > 2 || ft_atod(argv[2]) < -2)
		|| (ft_atod(argv[3]) > 2 || ft_atod(argv[3]) < -2))
	{
		ft_putstr_fd("Please write a correct input\n", 2);
		ft_putstr_fd("with (-2; -2) ≤ (x; y) ≤ (2; 2)\n", 2);
		ft_putstr_fd("Example: ./fractol julia 0.3 -0.56\n", 2);
		ft_putstr_fd("Example: ./fractol mandelbrot\n", 2);
		exit(1);
	}
}

//we want a funcion to checks if there is other thing written than numbers
//in the inputs' number (= our argv[2] && argv[3])
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
				ft_putstr_fd("Please write a correct input\n", 2);
				ft_putstr_fd("with (-2; -2) ≤ (x; y) ≤ (2; 2)\n", 2);
				ft_putstr_fd("Example: ./fractol julia 0.3 -0.56\n", 2);
				ft_putstr_fd("Example: ./fractol mandelbrot\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

//if there is more than 6 digits after the comma, and if the unit number is 2
//all of the decimals digits have to be 0. If not => exit(1);
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
					ft_putstr_fd("Please write a correct input ", 2);
					ft_putstr_fd("with (-2; -2) ≤ (x; y) ≤ (2; 2)\n", 2);
					ft_putstr_fd("Example: ./fractol julia 0.3 -0.56\n", 2);
					ft_putstr_fd("Example: ./fractol mandelbrot\n", 2);
					exit(1);
				}
			}
		}
	}
}

void	error_management(int argc, char **argv)
{
	if ((argc == 2 && !(ft_strncmp(argv[1], "mandelbrot", 10)))
		|| (argc == 2 && !(ft_strncmp(argv[1], "julia", 5))))
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
		ft_putstr_fd("Please write a correct input ", 2);
		ft_putstr_fd("with (-2; -2) ≤ (x; y) ≤ (2; 2)\n", 2);
		ft_putstr_fd("Example: ./fractol julia 0.3 -0.56\n", 2);
		ft_putstr_fd("Example: ./fractol mandelbrot\n", 2);
		exit(1);
	}
}
/*
#include <stdlib.h>
int	main(int argc, char **argv)
{
	double	result_lib;
	double	result_sim;

	if (argc == 4)
	{
		result_lib = atof(argv[2]);	
		printf("lib: %f\n", result_lib);
		result_sim = ft_atod(argv[2]);
		printf("sim: %f\n", result_sim);
		check_range(argv);
		check_numbers(argc, argv);
		check_decimals(argc, argv);
		printf("everything ok\n");
	}
	else
		printf("print one number\n");
	return (0);
}*/

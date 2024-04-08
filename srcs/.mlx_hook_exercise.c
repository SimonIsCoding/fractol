/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .mlx_hook_exercise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:56:12 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/30 20:33:08 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

/*typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	keycode = 0;
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 0, close, &vars);
	mlx_loop(vars.mlx);
}*/
//#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
//	if (keycode == 4)
//	{
		printf("%i\n", keycode);
//	}
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	if (keycode == 4)
	{
		printf("Scroll mouse!\n");
	}
	return (0);
}

/*int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}*/

/*int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_loop(img.mlx);
}
*/

#include <stdio.h>

int mandelbrot(double real, double imag, int max_iterations) {
    double z_real = 0.0, z_imag = 0.0;
    double temp_real, temp_imag;
    int iteration = 0;

    while (z_real*z_real + z_imag*z_imag < 4.0 && iteration < max_iterations) {
        temp_real = z_real*z_real - z_imag*z_imag + real;
        temp_imag = 2.0*z_real*z_imag + imag;
        z_real = temp_real;
        z_imag = temp_imag;
        iteration++;
    }

    return iteration;
}

int main() {
    int max_iterations = 100;
    double real, imag;

    // Parcours de la région rectangulaire du plan complexe défini par le coin supérieur gauche (xmin, ymin)
    // et le coin inférieur droit (xmax, ymax)
    double xmin = -2.0, ymin = -1.5;
    double xmax = 1.0, ymax = 1.5;

    // Résolution de l'image
    int width = 80, height = 40;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Conversion des coordonnées de pixel en coordonnées complexes
            real = xmin + (xmax - xmin) * x / (double)width;
            imag = ymin + (ymax - ymin) * y / (double)height;

            // Calcul de la valeur de la couleur pour le pixel
            int color = mandelbrot(real, imag, max_iterations);

            // Affichage du pixel avec une couleur basée sur le nombre d'itérations
            if (color == max_iterations)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}


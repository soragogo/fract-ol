/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:08:17 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/31 14:51:44 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <printf.h>

#include "mlx.h"
#include <stdio.h>
#include "../includes/fractol.h"

#include <string.h>

void	write_error_message(void)
{
	const char	*str;

	str = "Invalid or no parameter provided.\n";
	write(1, str, 33);
	str = "Please provide one of the following parameters:\n";
	write(1, str, 49);
	str = "1. julia z_real z_imag - to generate and display a Julia set. ";
	write(1, str, 62);
	str = "(where z_real, z_imag are numbers in the range -2.0 to 2.0)\n";
	write(1, str, 60);
	str = "2. mandelbrot - to generate and display a Mandelbrot set.\n";
	write(1, str, 54);
	str = "For example, to display a Julia set, run: ./fractol julia 1.0 0.5\n";
	write(1, str, 70);
}

int	main(int ac, char *av[])
{
	float	real;
	float	img;

	if (error_handling_and_arg_convert(ac, av, &real, &img))
	{
		write_error_message();
		return (0);
	}
	new_image(av[1][0], real, img);
	return (0);
}

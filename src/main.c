/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:08:17 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 10:56:36 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <printf.h>

#include "mlx.h"
#include <stdio.h>
#include "../includes/fractol.h"

void    write_error_message()
{
    char    *str;

    str = "Invalid or no parameter provided.\n";
    write(1, str, 37);
    str = "Please provide one of the following parameters:\n";
    write(1, str, 49);
    str = "1. julia - to generate and display a Julia set.\n";
    write(1, str, 50);
    str = "2. mandelbrot - to generate and display a Mandelbrot set.\n";
    write(1, str, 60);
    str = "For example, to display a Julia set, run: ./fractol julia z_real z_imag";
    write(1, str, 72);
}


int main(int ac, char *av[])
{
    float	real;
	float	img;
    if (error_handling_and_arg_convert(ac, av, &real, &img))
    {
        write_error_message();
        return (0);
    }
    printf("%f, %f\n", real, img);
    new_image(av[1][0], real, img);



    return (0);
}

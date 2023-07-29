/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:08:17 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 06:50:28 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <printf.h>

#include "mlx.h"
#include <stdio.h>
#include "../includes/fractol.h"




int main(int ac, char *av[])
{
    float	real;
	float	img;
    if (error_handling_and_arg_convert(ac, av, &real, &img))
    {
        printf("Invalid arguments\n");
        return (0);
    }
    printf("%f, %f\n", real, img);
    new_image(av[1][0], real, img);



    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:06:32 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 11:14:48 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <printf.h>

#include "mlx.h"
#include <stdio.h>
#include "../includes/fractol.h"

void	draw_image(mlx_list *list)
{
	// int		bits_per_pixel;
    // int		line_length;
    // int		endian;
	int		divergence;

	list->img_data = mlx_get_data_addr(list->img_ptr, &(list->bits_per_pixel), &(list->line_length), &(list->endian));

    for (float y = 0; y < LENGTH; y++)
    {
        for (float x = 0; x < LENGTH; x++)
        {
            int pixel_index =  y * list->line_length + x * list->bits_per_pixel/8;
			if (list->j_or_m == 'j')
            	divergence = julia_and_mandelbrot((x * list->size / LENGTH) - (list->size / 2) , (y * list->size / LENGTH) - (list->size / 2), list->real, list->img);
			else
				divergence = julia_and_mandelbrot(0, 0, (x * list->size / LENGTH) - (list->size / 2) , (y * list->size / LENGTH) - (list->size / 2));
            *(int*)(list->img_data + pixel_index) = rgb_generator(divergence);
        }
    }
}

int draw_frame(void *param)
{
    mlx_list    *list;

    list = (mlx_list *)param;
    mlx_put_image_to_window(list->mlx_ptr, list->win_ptr, list->img_ptr, 0, 0);
    return (0);
}

void	new_image(char argv1_0, float real, float imag)
{
	mlx_list list;

	list.real = real;
	list.img = imag;
	list.j_or_m = argv1_0;
    list.mlx_ptr = mlx_init();
	list.size = 4;
    list.win_ptr = mlx_new_window(list.mlx_ptr, LENGTH, LENGTH, "my_julia_test");
    list.img_ptr = mlx_new_image(list.mlx_ptr, LENGTH, LENGTH);
	draw_image(&list);
    mlx_put_image_to_window(list.mlx_ptr, list.win_ptr, list.img_ptr, 0, 0);
    printf("new_image: %p\n", list.win_ptr);
    mlx_key_hook(list.win_ptr, exit_program, &list);
	mlx_hook(list.win_ptr, 17, 0, &close_program, NULL);
    mlx_mouse_hook(list.win_ptr, scroll_event, &list);
    mlx_loop_hook(list.mlx_ptr, &draw_frame, &list);
    mlx_loop(list.mlx_ptr);

}

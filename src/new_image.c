/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:06:32 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 09:32:37 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <printf.h>

#include "mlx.h"
#include <stdio.h>
#include "../includes/fractol.h"

void	draw_image(mlx_list *list)
{
	int		bits_per_pixel;
    int		line_length;
    int		endian;
	int		divergence;

	list->img_data = mlx_get_data_addr(list->img_ptr, &bits_per_pixel, &line_length, &endian);

    for (float y = 0; y < LENGTH; y++)
    {
        for (float x = 0; x < LENGTH; x++)
        {
            // int pixel_index = (y * LENGTH + x) * 4; // 各ピクセルは4バイト
            int pixel_index =  y * line_length + x * bits_per_pixel/8;
			if (list->j_or_m == 'j')
            	divergence = julia_and_mandelbrot((x * list->size / LENGTH) - (list->size / 2) , (y * list->size / LENGTH) - (list->size / 2), list->real, list->img);
			else
				divergence = julia_and_mandelbrot(0, 0, (x * list->size / LENGTH) - (list->size / 2) , (y * list->size / LENGTH) - (list->size / 2));
            *(int*)(list->img_data + pixel_index) = rgb_generator(divergence);
        }
    }


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

    // 新しいイメージを作成
    list.img_ptr = mlx_new_image(list.mlx_ptr, LENGTH, LENGTH);
	draw_image(&list);

    // イメージをウィンドウに描画する
    mlx_put_image_to_window(list.mlx_ptr, list.win_ptr, list.img_ptr, 0, 0);

	mlx_key_hook(list.win_ptr, exit_program, list.mlx_ptr);
	mlx_hook(list.win_ptr, 17, 0, &close_program, NULL);
	// mlx_hook(list.win_ptr, 4, 0, scroll_event, &list);
    mlx_mouse_hook(list.win_ptr, scroll_event, &list);
    mlx_loop(list.mlx_ptr);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:06:32 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/31 14:36:50 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <printf.h>

#include "mlx.h"
#include <stdio.h>
#include "../includes/fractol.h"

void	draw_image(mlx_list *list, float x, float y)
{
	int		div;
	float	x_coor;
	float	y_coor;
	int		pixel_index;

	x_coor = (x * list->size / LENGTH) - (list->size / 2);
	y_coor = (y * list->size / LENGTH) - (list->size / 2);
	list->img_data = mlx_get_data_addr(list->img_ptr,
			&(list->bits_per_pixel), &(list->line_length), &(list->endian));
	while (x < LENGTH)
	{
		while (y < LENGTH)
		{
			pixel_index = y * list->line_length + x * list->bits_per_pixel / 8;
			if (list->j_or_m == 'j')
				div = cal_divergence(x_coor, y_coor, list->real, list->img);
			else
				div = cal_divergence(0, 0, x_coor, y_coor);
			*(int *)(list->img_data + pixel_index) = rgb_generator(div);
			y++;
		}
		x++;
	}
}

int	draw_frame(void *param)
{
	mlx_list	*list;

	list = (mlx_list *)param;
	mlx_put_image_to_window(list->mlx_ptr, list->win_ptr, list->img_ptr, 0, 0);
	return (0);
}

void	new_image(char argv1_0, float real, float imag)
{
	mlx_list	list;

	list.real = real;
	list.img = imag;
	list.j_or_m = argv1_0;
	list.mlx_ptr = mlx_init();
	list.size = 4;
	list.win_ptr = mlx_new_window(list.mlx_ptr, LENGTH, LENGTH, "fract-ol");
	list.img_ptr = mlx_new_image(list.mlx_ptr, LENGTH, LENGTH);
	draw_image(&list, 0, 0);
	mlx_put_image_to_window(list.mlx_ptr, list.win_ptr, list.img_ptr, 0, 0);
	printf("new_image: %p\n", list.win_ptr);
	mlx_key_hook(list.win_ptr, exit_program, &list);
	mlx_hook(list.win_ptr, 17, 0, &close_program, NULL);
	mlx_mouse_hook(list.win_ptr, scroll_event, &list);
	mlx_loop_hook(list.mlx_ptr, &draw_frame, &list);
	mlx_loop(list.mlx_ptr);
}

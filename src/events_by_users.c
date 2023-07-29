/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_by_users.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:45:56 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 09:32:35 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <printf.h>

#include "mlx.h"
#include <stdio.h>
#include "../includes/fractol.h"

int exit_program(int keycode, void *param)
{
	printf("this is keycode :%d\n", keycode);
	if (keycode == 65307)
	{
    	mlx_loop_end(param);
    	return (0);
	}
	return (0);
}

int	close_program(void *param)
{
	(void)param;
	exit(0);
	return (0);
}



int	scroll_event(int keycode, int x, int y, void *param)
{
	mlx_list *list;
	printf("thisi s my ketyxods%d\n", keycode);
	printf("hellooooo");

	x = 0;
	y = 0;
	list = (mlx_list *)param;
	if (keycode == 4)
	{
		list->size *= 1.1;
		mlx_clear_window(list->mlx_ptr, list->win_ptr);
		draw_image(list);
		mlx_put_image_to_window(list->mlx_ptr, list->win_ptr, list->img_ptr, 0, 0);
	}
	else if (keycode == 5)
	{
		list->size /= 1.1;
		mlx_clear_window(list->mlx_ptr, list->win_ptr);
		draw_image(list);
		mlx_put_image_to_window(list->mlx_ptr, list->win_ptr, list->img_ptr, 0, 0);
	}
	return (0);
}

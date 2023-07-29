/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:24:34 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 11:12:38 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <libc.h>

typedef struct s_list{

	float	size;
	void	*mlx_ptr;
    void	*win_ptr;
    void	*img_ptr;
    char	*img_data;
	char	j_or_m;
	float	real;
	float	img;
	int		bits_per_pixel;
    int		line_length;
    int		endian;

}	mlx_list;

# ifndef LENGTH
#  define LENGTH 800
# endif

int		julia_and_mandelbrot(float x, float y, float a, float b);
int		rgb_generator(int divergence);
int		error_handling_and_arg_convert(int ac, char *av[], float *real, float *img);
int		exit_program(int keycode, mlx_list *list);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	new_image(char j_or_m, float real, float img);
int		close_program(void *param);
int		scroll_event(int keycode, int x, int y, void *param);
void	draw_image(mlx_list *list);



# endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_and_mandelbrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:29:30 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 10:04:17 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_and_mandelbrot(float x, float y, float a, float b)
{
	float	z_real = x;
	float	z_imag = y;
	float	tmp_real = 0;
	float	tmp_imag = 0;
	int		loop;

	loop = 1;
	while (loop < 255)
	{
		tmp_real = z_real * z_real - z_imag * z_imag + a;
		tmp_imag = 2 * z_real * z_imag + b;
		if ((tmp_real * tmp_real) + (tmp_imag * tmp_imag) >= 4)
			return (loop);
		z_real = tmp_real;
		z_imag = tmp_imag;
		loop++;
	}
	return (0);
}

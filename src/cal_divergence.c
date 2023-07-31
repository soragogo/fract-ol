/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_divergence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:29:30 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/31 14:43:26 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	cal_divergence(float x, float y, float a, float b)
{
	float	z_real;
	float	z_imag;
	float	tmp_real;
	float	tmp_imag;
	int		loop;

	z_real = x;
	z_imag = y;
	tmp_real = 0;
	tmp_imag = 0;
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

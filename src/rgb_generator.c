/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:22:42 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/29 07:34:43 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb_generator(int divergence)
{
	int	r;
	int	g;
	int	b;

	r = (divergence % 128 * 2) << 16;
	g = (divergence % 256) << 8;
	b = (divergence % 64 * 4) << 0;
	return (r + g + b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_hand_arg_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekamada <ekamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:22:45 by ekamada           #+#    #+#             */
/*   Updated: 2023/07/31 14:44:57 by ekamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

#include <stdio.h>
#include "../includes/fractol.h"

float	after_point(char *av, int i)
{
	float	result;
	float	place;

	if (av[i] == '.')
		i++;
	else
		return (0);
	result = 0;
	place = 1;
	if (av[i] == '\0')
		return (0);
	while (av[i] != '\0')
	{
		place *= 10;
		result += (av[i] - '0') / place;
		i++;
	}
	printf("result: %f\n", result);
	return (result);
}

float	a_to_float(int *error_num, char *av)
{
	float	result;
	float	minus;
	int		i;

	minus = 1;
	result = 0;
	i = 0;
	if (av[i] == '-')
		minus *= -1;
	if (av[i] == '-' || av[i] == '+')
		i ++;
	while (av[i] != '.' && av[i] != '\0')
	{
		if (result != 0 && av[i] != '.')
			*error_num = 1;
		result = av[i] - '0';
		i++;
	}
	result += after_point(av, i);
	if (result > 2)
		*error_num = 1;
	return (minus * result);
}

int	is_int_or_float(char *av[])
{
	int	point_count;
	int	i;
	int	j;

	point_count = 0;
	i = 2;
	while (i < 4)
	{
		j = 0;
		point_count = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == '.')
				point_count++;
			else if (j == 0 && (av[i][j] == '+' || av[i][j] == '-'))
				;
			else if (av[i][j] > '9' || av[i][j] < '0')
				return (1);
			if (point_count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_handling_and_arg_convert(int ac, char *av[], float *real, float *img)
{
	int		error_num;

	error_num = 0;
	if (!(ac == 2 || ac == 4))
		return (1);
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
	{
		*real = 0;
		*img = 0;
		return (0);
	}
	else if (ft_strncmp(av[1], "julia", 6) == 0 && ac == 4)
	{
		if (!*av[2] || !*av[3])
			return (1);
		if (is_int_or_float(av) != 0)
			return (1);
		*real = a_to_float(&error_num, av[2]);
		*img = a_to_float(&error_num, av[3]);
		if (error_num != 0)
			return (1);
		return (0);
	}
	return (1);
}

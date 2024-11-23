/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:51:47 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 10:59:42 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

void	ft_color_pixel(int color, int pixel, char *buffer)
{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
}

void	ft_display_pixel(t_pixel pixel, char *s)
{
	ft_printf("\npixel %s, x:%d, y:%d\n", s, pixel.x, pixel.y);
}

double	ft_get_smooth_iter(t_pixel pixel, t_data data)
{
	double	iter;

	iter = 0;
	if (data.fract.fract_set == 1)
		iter = ft_get_smooth_mandel_iter(pixel, data);
	else if (data.fract.fract_set == 2)
		iter = ft_get_smooth_ship_iter(pixel, data);
	return (iter);
}

double	ft_smoothen_iter(t_complex escape, t_data data)
{
	double	smooth_iter;
	double	abs_z;

	if (escape.iter == data.fract.max_iter)
		smooth_iter = data.fract.max_iter + 30;
	else
	{
		abs_z = escape.x * escape.x + escape.y * escape.y;
		abs_z = log(log(abs_z) / log(2)) / log(2);
		smooth_iter = sqrt(escape.iter + 10 - abs_z);
	}
	return (smooth_iter);
}

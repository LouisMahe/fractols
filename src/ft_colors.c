/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:31:32 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 10:31:33 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

int	ft_gray(int iteration, int max_iter)
{
	double	t;
	int		intensity;
	int		color;

	t = tanh(10 * (double)(iteration) / max_iter);
	intensity = (int)(t * 255);
	color = (intensity << 16) | (intensity << 8) | intensity | 0x00000000;
	return (color);
}

int	ft_interpol(int iteration, int max_iter)
{
	float	lambda;
	float	mu;
	int		color_blue;
	int		color_black;
	int		color;

	color_black = 0x0000ff22;
	color_blue = 0xff0022ff;
	lambda = (float)iteration / max_iter;
	mu = ((float)max_iter - iteration) / max_iter;
	color = (int)(color_black * mu + lambda * color_blue);
	return (color);
}

int	ft_get_palette(int iter)
{
	int	palette[16];

	palette[0] = 0x00d6edf0;
	palette[1] = 0x00c4e5e9;
	palette[2] = 0x0090c9d0;
	palette[3] = 0x0063b5be;
	palette[4] = 0x00409aa5;
	palette[5] = 0x001e6284;
	palette[6] = 0x00347da2;
	palette[7] = 0x005790ad;
	palette[8] = 0x00c7d9e2;
	palette[9] = 0x0093a4bf;
	palette[10] = 0x00f486e0;
	palette[11] = 0x002b5dae;
	palette[12] = 0x00113166;
	palette[13] = 0x00244172;
	palette[14] = 0x003b388a;
	palette[15] = 0x005d5b95;
	return (palette[iter % 16]);
}

int	ft_get_first_palette(int iter, t_data data)
{
	int	res;
	int	color;

	res = (iter * 256) % 2048;
	color = data.fract.palette[res];
	return (color);
}

int	ft_simple_color(int iter)
{
	int	color;

	color = 0x00000000;
	color |= (0xfc * iter) % 256 << 16;
	color |= (0xbe * iter) % 256 << 8;
	color |= (0x11 * iter) % 256;
	return (color);
}

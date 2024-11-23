/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubic_interpol2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:50:32 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:26:07 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_cubic	ft_cubic_green_init1(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 7;
	t_red.y[1] = 107;
	t_red.y[2] = 255;
	t_red.y[3] = 170;
	t_red.y[4] = 2;
	t_red.y[5] = 0;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_blue_init1(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 100;
	t_red.y[1] = 203;
	t_red.y[2] = 255;
	t_red.y[3] = 0;
	t_red.y[4] = 0;
	t_red.y[5] = 58;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_red_init1(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0;
	t_red.y[1] = 32;
	t_red.y[2] = 237;
	t_red.y[3] = 255;
	t_red.y[4] = 0;
	t_red.y[5] = 0;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

double	ft_interpol_val(double x, t_cubic color)
{
	int			i;
	double		delta;
	double		t;
	double		res;
	t_hermite	t_h;

	i = 0;
	res = 0;
	while (x > color.x[i + 1])
		i++;
	delta = color.x[i + 1] - color.x[i];
	t = (x - color.x[i]) / delta;
	ft_get_hermite(t, &t_h);
	res += color.y[i] * t_h.h00;
	res += delta * color.m[i] * t_h.h10;
	res += color.y[i + 1] * t_h.h01;
	res += delta * color.m[i + 1] * t_h.h11;
	return (res);
}

int	*ft_cubic_first_palette(int size)
{
	t_cubic	t_red;
	t_cubic	t_green;
	t_cubic	t_blue;
	int		i;
	int		*palette;

	t_red.x[0] = 0;
	t_green.x[0] = 0;
	t_blue.x[0] = 0;
	t_red = ft_cubic_red_init1(t_red);
	t_green = ft_cubic_green_init1(t_green);
	t_blue = ft_cubic_blue_init1(t_blue);
	palette = malloc(size * sizeof(int));
	if (!palette)
		return (NULL);
	i = 0;
	while (i < size)
	{
		palette[i] = 0x00000000;
		palette[i] |= (int)ft_interpol_val((double)i / size, t_red) << 16;
		palette[i] |= (int)ft_interpol_val((double)i / size, t_green) << 8;
		palette[i] |= (int)ft_interpol_val((double)i / size, t_blue);
		i++;
	}
	return (palette);
}

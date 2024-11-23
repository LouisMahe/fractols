/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:34:53 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:12:51 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

int	ft_interpolate(double iter)
{
	int		color1;
	int		color2;
	int		color;
	double	t;

	color1 = ft_get_palette(floor(iter));
	color2 = ft_get_palette(floor(iter) + 1);
	t = iter - floor(iter);
	color = (int)(t * color1 + (1 - t) * color2);
	return (color);
}

int	ft_first_palette(double iter, t_data data)
{
	int	res;
	int	color;

	res = ((int)(iter * 256)) % 2048;
	color = data.fract.palette[res];
	return (color);
}

int	ft_scd_palette(double iter, t_data data)
{
	int	res;
	int	color;

	res = ((int)(iter * 256)) % 2048;
	color = data.fract.palette2[res];
	return (color);
}

int	ft_thrd_palette(double iter, t_data data)
{
	int	res;
	int	color;

	res = ((int)(iter * 256)) % 2048;
	color = data.fract.palette3[res];
	return (color);
}

int	ft_fourth_palette(double iter, t_data data)
{
	int	res;
	int	color;

	res = ((int)(iter * 256)) % 2048;
	color = data.fract.palette4[res];
	return (color);
}

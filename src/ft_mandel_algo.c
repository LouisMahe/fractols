/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:23:46 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 10:50:12 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

int	ft_mandel_get_color(int iter, t_data data)
{
	int	color;

	color = 0x00000000;
	if (iter < data.fract.max_iter)
	{
		if (data.fract.color_number == 0)
			color = ft_gray(iter, data.fract.max_iter);
		else if (data.fract.color_number == 1)
			color = ft_interpol(iter, data.fract.max_iter);
		else if (data.fract.color_number == 2)
			color = ft_get_palette(iter);
		else if (data.fract.color_number == 3)
			color = ft_simple_color(iter);
		else
			color = ft_get_first_palette(iter, data);
	}
	return (color);
}

int	ft_cardio_check(double x, double y)
{
	double	q;
	double	is_in_set;

	q = (x - 0.25) * (x - 0.25) + y * y;
	is_in_set = q * (q + x - 0.25) - 0.25 * y * y;
	if (is_in_set <= 0)
		return (1);
	is_in_set = x * x + x + x + 1 + y * y - 0.0625;
	if (is_in_set <= 0)
		return (1);
	return (0);
}

int	ft_get_mandel_iter(int pixelx, int pixely, int max_iter, t_data data)
{
	t_complex	t_c;
	t_complex	t_zn;
	t_complex	t_norm;
	int			iter;

	t_c.x = data.fract.x_min + pixelx * data.fract.xstep;
	t_c.y = data.fract.y_max - pixely * data.fract.ystep;
	if (ft_cardio_check(t_c.x, t_c.y) == 1)
		return (max_iter);
	t_zn.x = 0;
	t_zn.y = 0;
	t_norm.x = 0;
	t_norm.y = 0;
	iter = 0;
	while (t_norm.x + t_norm.y <= 4 && iter < max_iter)
	{
		t_zn.y = 2 * t_zn.x * t_zn.y + t_c.y;
		t_zn.x = t_norm.x - t_norm.y + t_c.x;
		t_norm.x = t_zn.x * t_zn.x;
		t_norm.y = t_zn.y * t_zn.y;
		iter ++;
	}
	return (iter);
}

int	ft_get_iter(t_pixel pixel, t_data data)
{
	int	iter;

	iter = 0;
	if (data.fract.fract_set == 1)
		iter = ft_get_mandel_iter(pixel.x, pixel.y, data.fract.max_iter, data);
	else if (data.fract.fract_set == 2)
		iter = ft_get_ship_iter(pixel, data);
	return (iter);
}

int	ft_draw_mandel(t_data *data)
{
	if (!data->fract.mlx_img)
		return (0);
	if (data->fract.smoothed == 0)
		ft_draw_mandel_rectangle(data);
	else if (data->fract.smoothed == 1)
		ft_draw_smooth_mandel(data);
	return (1);
}

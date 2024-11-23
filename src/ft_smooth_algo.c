/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:11:26 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:11:27 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_complex	ft_get_mandel_smooth_iter(t_pixel pixel, t_data data)
{
	t_complex	t_c;
	t_complex	t_zn;
	t_complex	t_norm;

	t_norm.iter = data.fract.max_iter;
	t_c.x = data.fract.x_min + pixel.x * data.fract.xstep;
	t_c.y = data.fract.y_max - pixel.y * data.fract.ystep;
	if (ft_cardio_check(t_c.x, t_c.y) == 1)
		return (t_norm);
	t_zn.x = 0;
	t_zn.y = 0;
	t_norm.x = 0;
	t_norm.y = 0;
	t_norm.iter = 0;
	while (t_norm.x + t_norm.y <= data.fract.smooth_bound \
		&& t_norm.iter < data.fract.max_iter)
	{
		t_zn.y = 2 * t_zn.x * t_zn.y + t_c.y;
		t_zn.x = t_norm.x - t_norm.y + t_c.x;
		t_norm.x = t_zn.x * t_zn.x;
		t_norm.y = t_zn.y * t_zn.y;
		t_norm.iter ++;
	}
	return (t_norm);
}

double	ft_get_smooth_mandel_iter(t_pixel pixel, t_data data)
{
	t_complex	t_result;
	double		smooth_iter;
	double		nu;
	double		log_norm;

	t_result = ft_get_mandel_smooth_iter(pixel, data);
	if (t_result.iter == data.fract.max_iter)
		return (data.fract.max_iter + 30);
	else
	{
		log_norm = log(t_result.x + t_result.y) * 0.5;
		nu = log(log(log_norm) / log(2)) / log(2);
		smooth_iter = sqrt(t_result.iter + 10 - nu);
		return (smooth_iter);
	}
}

int	ft_get_smooth_color(double iter, t_data data)
{
	int	color;

	if (iter > data.fract.max_iter + 20)
		color = BLACK;
	else
	{
		if (data.fract.color_number == 0)
			color = ft_scd_palette(iter, data);
		else if (data.fract.color_number == 1)
			color = ft_interpolate(iter);
		else if (data.fract.color_number == 2)
			color = ft_thrd_palette(iter, data);
		else if (data.fract.color_number == 3)
			color = ft_fourth_palette(iter, data);
		else
			color = ft_first_palette(iter, data);
	}
	return (color);
}

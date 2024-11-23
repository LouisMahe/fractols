/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ship_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:12:26 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:07:51 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_complex	ft_ship_iter(t_pixel pixel, t_data data)
{
	t_complex	t_c;
	t_complex	t_z;
	t_complex	t_norm;
	int			iter;

	t_c.x = data.fract.x_min + pixel.x * data.fract.xstep;
	t_c.y = data.fract.y_max + pixel.y * data.fract.ystep;
	t_z.x = 0;
	t_z.y = 0;
	t_norm.x = 0;
	t_norm.y = 0;
	iter = 0;
	while (t_norm.x + t_norm.y <= 4 && iter < data.fract.max_iter)
	{
		t_z.y = fabs(2 * t_z.x * t_z.y) + t_c.y;
		t_z.x = t_norm.x - t_norm.y + t_c.x;
		t_norm.x = t_z.x * t_z.x;
		t_norm.y = t_z.y * t_z.y;
		iter ++;
	}
	t_norm.iter = iter;
	return (t_norm);
}

double	ft_get_smooth_ship_iter(t_pixel pixel, t_data data)
{
	t_complex	res;
	double		log_norm;
	double		nu;
	double		smooth_iter;

	res = ft_ship_iter(pixel, data);
	if (res.iter == data.fract.max_iter)
		smooth_iter = data.fract.max_iter + 30;
	else
	{
		log_norm = log(res.x + res.y) * 0.5;
		nu = log(log(log_norm) / log(2)) / log(2);
		smooth_iter = sqrt(res.iter + 10 - nu);
	}
	return (smooth_iter);
}

int	ft_get_ship_iter(t_pixel pixel, t_data data)
{
	t_complex	res;

	res = ft_ship_iter(pixel, data);
	return (res.iter);
}

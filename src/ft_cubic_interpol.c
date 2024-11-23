/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubic_interpol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:19:25 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 10:33:37 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

void	ft_init_xpoint(t_cubic *t_color)
{
	t_color->x[0] = 0;
	t_color->x[1] = 0.16;
	t_color->x[2] = 0.42;
	t_color->x[3] = 0.6425;
	t_color->x[4] = 0.8575;
	t_color->x[5] = 1;
}

void	ft_get_delta(t_cubic *t_color)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		t_color->d[i] = (t_color->y[i + 1] - t_color->y[i]) \
			/ (t_color->x[i + 1] - t_color->x[i]);
		i++;
	}
	t_color->d[5] = 0;
}

void	ft_get_m(t_cubic *t_color)
{
	int	i;

	t_color->m[0] = t_color->d[1];
	t_color->m[5] = t_color->d[5];
	i = 1;
	while (i < 5)
	{
		if (t_color->d[i - 1] * t_color->d[i] < 0)
			t_color->m[i] = 0;
		else if (t_color->d[i - 1] == 0 || t_color->d[i] == 0)
			t_color->m[i] = 0;
		else
			t_color->m[i] = (t_color->d[i - 1] + t_color->d[i]) * 0.5;
		i++;
	}
}

void	ft_rescale(t_cubic *t_color)
{
	double	alpha;
	double	beta;
	double	t;
	int		i;

	i = 0;
	while (i < 6)
	{
		if (t_color->d[i] != 0)
		{
			alpha = t_color->m[i] / t_color->d[i];
			beta = t_color->m[i + 1] / t_color->d[i];
			if (alpha * alpha + beta * beta > 9)
			{
				t = 3 / (sqrt(alpha * alpha + beta * beta));
				t_color->m[i] = t * alpha * t_color->d[i];
				t_color->m[i + 1] = t * beta * t_color->d[i];
			}
		}
		i++;
	}
}

void	ft_get_hermite(double t, t_hermite *t_h)
{
	double	t_cube;
	double	t_square;

	t_square = t * t;
	t_cube = t * t * t;
	t_h->h00 = 2 * t_cube - 3 * t_square + 1;
	t_h->h10 = t_cube - 2 * t_square + t;
	t_h->h01 = -2 * t_cube + 3 * t_square;
	t_h->h11 = t_cube - t_square;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:06:21 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:52:03 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_fract	ft_init_julia(t_data data, t_fract t_julia, double x, double y)
{
	t_julia = ft_init_palettes(data, t_julia);
	t_julia.mlx_img = mlx_new_image(data.pmlx, WIDTH, HEIGHT);
	if (t_julia.mlx_img == NULL)
	{
		free(t_julia.palette4);
		ft_palette_error(data, t_julia.palette, t_julia.palette2, \
			t_julia.palette3);
	}
	t_julia.addr = mlx_get_data_addr(t_julia.mlx_img, \
		&t_julia.bpp, &t_julia.line_len, &t_julia.endian);
	t_julia.color_number = 0;
	t_julia.smoothed = 0;
	t_julia.fract_set = 0;
	t_julia.x_center = 0.0;
	t_julia.y_center = 0.0;
	t_julia.julia_cx = x;
	t_julia.julia_cy = y;
	t_julia.max_iter = 1000;
	t_julia.zoom = 1;
	t_julia.x_min = t_julia.x_center - XSTEP * WIDTH * t_julia.zoom * 0.5;
	t_julia.y_max = t_julia.y_center + YSTEP * HEIGHT * t_julia.zoom * 0.5;
	t_julia.xstep = XSTEP * t_julia.zoom;
	t_julia.ystep = YSTEP * t_julia.zoom;
	return (t_julia);
}

int	ft_julia_smooth_color(t_complex escape, t_data data)
{
	double	iter;
	int		color;

	iter = ft_smoothen_iter(escape, data);
	color = ft_get_smooth_color(iter, data);
	return (color);
}

t_complex	ft_get_julia_iter(t_pixel pixel, int max_iter, t_data data)
{
	t_complex	z;
	double		temp;
	int			i;

	z.x = data.fract.x_min + data.fract.xstep * pixel.x;
	z.y = data.fract.y_max - data.fract.ystep * pixel.y;
	i = 0;
	while (z.x * z.x + z.y * z.y < 4 && i < max_iter)
	{
		temp = z.x * z.x - z.y * z.y;
		z.y = 2 * z.x * z.y + data.fract.julia_cy;
		z.x = temp + data.fract.julia_cx;
		i++;
	}
	z.iter = i;
	return (z);
}

int	ft_julia_color(t_complex escape, t_data data)
{
	int	color;

	if (escape.iter > data.fract.max_iter + 20)
		color = BLACK;
	else
	{
		if (data.fract.smoothed == 1)
			color = ft_julia_smooth_color(escape, data);
		else
			color = ft_mandel_get_color(escape.iter, data);
	}
	return (color);
}

int	ft_draw_julia(t_data *data)
{
	t_pixel		t_pixel;
	t_complex	escape;
	int			color;

	if (!data->fract.mlx_img)
		return (0);
	t_pixel.x = 0;
	t_pixel.y = 0;
	while (t_pixel.x < WIDTH)
	{
		while (t_pixel.y < HEIGHT)
		{
			t_pixel.pix_adr = t_pixel.y * data->fract.line_len \
				+ t_pixel.x * (data->fract.bpp / 8);
			escape = ft_get_julia_iter(t_pixel, data->fract.max_iter, *data);
			color = ft_julia_color(escape, *data);
			ft_color_pixel(color, t_pixel.pix_adr, data->fract.addr);
			t_pixel.y++;
		}
		t_pixel.x++;
		t_pixel.y = 0;
	}
	mlx_put_image_to_window(data->pmlx, data->pwin, data->fract.mlx_img, 0, 0);
	return (1);
}

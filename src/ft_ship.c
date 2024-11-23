/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:34:54 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:52:32 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_fract	ft_init_ship(t_data data, t_fract t_ship, void *mlx)
{
	t_ship = ft_init_palettes(data, t_ship);
	t_ship.mlx_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (t_ship.mlx_img == NULL)
	{
		free(t_ship.palette4);
		ft_palette_error(data, t_ship.palette, t_ship.palette2, \
			t_ship.palette3);
	}
	t_ship.addr = mlx_get_data_addr(t_ship.mlx_img, \
		&t_ship.bpp, &t_ship.line_len, &t_ship.endian);
	t_ship.fract_set = 2;
	t_ship.x_center = -0.7;
	t_ship.y_center = 0;
	t_ship.max_iter = 1000;
	t_ship.color_number = 0;
	t_ship.smoothed = 0;
	t_ship.smooth_bound = 1 << 16;
	t_ship.zoom = 1;
	t_ship.x_min = t_ship.x_center - XSTEP * t_ship.zoom * WIDTH * 0.5;
	t_ship.y_max = t_ship.y_center - YSTEP * t_ship.zoom * HEIGHT * 0.5;
	t_ship.xstep = XSTEP * t_ship.zoom;
	t_ship.ystep = YSTEP * t_ship.zoom;
	return (t_ship);
}

int	ft_draw_ship_rectangle(t_data *data)
{
	t_pixel	up_left;
	t_pixel	down_right;

	if (!data->fract.mlx_img)
		return (0);
	up_left.x = 0;
	up_left.y = 0;
	down_right.x = SUBSIZE;
	down_right.y = SUBSIZE;
	while (down_right.x <= WIDTH)
	{
		while (down_right.y <= HEIGHT)
		{
			ft_check_rectangle(up_left, down_right, \
				data->fract.max_iter, *data);
			up_left.y += SUBSIZE;
			down_right.y += SUBSIZE;
		}
		up_left.x += SUBSIZE;
		down_right.x = up_left.x + SUBSIZE;
		up_left.y = 0;
		down_right.y = SUBSIZE;
	}
	mlx_put_image_to_window(data->pmlx, data->pwin, data->fract.mlx_img, 0, 0);
	return (1);
}

int	ft_draw_smooth_ship(t_data *data)
{
	t_pixel	t_pixel;
	double	iter;
	int		color;

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
			iter = ft_get_smooth_ship_iter(t_pixel, *data);
			color = ft_get_smooth_color(iter, *data);
			ft_color_pixel(color, t_pixel.pix_adr, data->fract.addr);
			t_pixel.y++;
		}
		t_pixel.x++;
		t_pixel.y = 0;
	}
	mlx_put_image_to_window(data->pmlx, data->pwin, data->fract.mlx_img, 0, 0);
	return (1);
}

int	ft_draw_ship(t_data *data)
{
	if (!data->fract.mlx_img)
		return (0);
	if (data->fract.smoothed == 0)
		ft_draw_ship_rectangle(data);
	else if (data->fract.smoothed == 1)
		ft_draw_smooth_ship(data);
	return (1);
}

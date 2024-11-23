/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:54 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:12:31 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

int	ft_draw_smooth_mandel(t_data *data)
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
			ft_check_srectangle(up_left, down_right, \
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

void	ft_color_smooth_inside(t_pixel up_left, t_pixel down_right, \
	int max_iter, t_data data)
{
	t_pixel	t_pixel;
	double	iter;
	int		color;

	(void) max_iter;
	t_pixel.x = up_left.x;
	t_pixel.y = up_left.y;
	while (t_pixel.x <= down_right.x)
	{
		while (t_pixel.y <= down_right.y)
		{
			t_pixel.pix_adr = t_pixel.y * data.fract.line_len \
				+ t_pixel.x * (data.fract.bpp / 8);
			iter = ft_get_smooth_iter(t_pixel, data);
			color = ft_get_smooth_color(iter, data);
			ft_color_pixel(color, t_pixel.pix_adr, data.fract.addr);
			t_pixel.y += 1;
		}
		t_pixel.y = up_left.y + 1;
		t_pixel.x += 1;
	}
}

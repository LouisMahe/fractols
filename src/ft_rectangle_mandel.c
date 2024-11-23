/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle_mandel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:16:58 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:07:20 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

int	ft_check_up_border(t_pixel up_left, t_pixel down_right, \
	int max_iter, t_data data)
{
	t_pixel	pixel;
	int		color;
	int		is_all_set;
	int		iter;

	pixel.x = up_left.x;
	pixel.y = up_left.y;
	is_all_set = 1;
	while (pixel.x < down_right.x)
	{
		pixel.pix_adr = pixel.y * data.fract.line_len + \
			pixel.x * (data.fract.bpp / 8);
		iter = ft_get_iter(pixel, data);
		if (iter < max_iter)
			is_all_set = 0;
		color = ft_mandel_get_color(iter, data);
		ft_color_pixel(color, pixel.pix_adr, data.fract.addr);
		pixel.x = pixel.x + 1;
	}
	return (is_all_set);
}

int	ft_check_bottom_border(t_pixel up_left, t_pixel down_right, \
	int max_iter, t_data data)
{
	t_pixel	pixel;
	int		color;
	int		is_all_set;
	int		iter;

	pixel.x = up_left.x;
	pixel.y = down_right.y;
	is_all_set = 1;
	while (pixel.x < down_right.x)
	{
		pixel.pix_adr = pixel.y * data.fract.line_len + \
			pixel.x * (data.fract.bpp / 8);
		iter = ft_get_iter(pixel, data);
		if (iter < max_iter)
			is_all_set = 0;
		color = ft_mandel_get_color(iter, data);
		ft_color_pixel(color, pixel.pix_adr, data.fract.addr);
		pixel.x = pixel.x + 1;
	}
	return (is_all_set);
}

int	ft_check_left_border(t_pixel up_left, t_pixel down_right, \
	int max_iter, t_data data)
{
	t_pixel	pixel;
	int		color;
	int		is_all_set;
	int		iter;

	pixel.x = up_left.x;
	pixel.y = up_left.y;
	is_all_set = 1;
	while (pixel.y < down_right.y)
	{
		pixel.pix_adr = pixel.y * data.fract.line_len + \
			pixel.x * (data.fract.bpp / 8);
		iter = ft_get_iter(pixel, data);
		if (iter < max_iter)
			is_all_set = 0;
		color = ft_mandel_get_color(iter, data);
		ft_color_pixel(color, pixel.pix_adr, data.fract.addr);
		pixel.y = pixel.y + 1;
	}
	return (is_all_set);
}

int	ft_check_right_border(t_pixel up_left, t_pixel down_right, \
	int max_iter, t_data data)
{
	t_pixel	pixel;
	int		is_all_set;
	int		iter;
	int		color;

	pixel.x = down_right.x;
	pixel.y = up_left.y;
	is_all_set = 1;
	while (pixel.y < down_right.y)
	{
		pixel.pix_adr = pixel.y * data.fract.line_len + \
			pixel.x * (data.fract.bpp / 8);
		iter = ft_get_iter(pixel, data);
		if (iter < max_iter)
			is_all_set = 0;
		color = ft_mandel_get_color(iter, data);
		ft_color_pixel(color, pixel.pix_adr, data.fract.addr);
		pixel.y = pixel.y + 1;
	}
	return (is_all_set);
}

void	ft_check_rectangle(t_pixel up_left, t_pixel down_right, \
	int max_iter, t_data data)
{
	int	is_all_set;

	is_all_set = 1;
	is_all_set *= ft_check_up_border(up_left, down_right, max_iter, data);
	is_all_set *= ft_check_right_border(up_left, down_right, max_iter, data);
	is_all_set *= ft_check_left_border(up_left, down_right, max_iter, data);
	is_all_set *= ft_check_bottom_border(up_left, down_right, max_iter, data);
	if (is_all_set == 1)
		ft_color_inside_black(up_left, down_right, data);
	else
		ft_color_inside(up_left, down_right, max_iter, data);
}

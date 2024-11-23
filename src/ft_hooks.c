/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:51:48 by lmahe             #+#    #+#             */
/*   Updated: 2024/11/23 19:11:46 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"


int	ft_update_corner(t_fract *fract)
{
	fract->x_min = fract->x_center - fract->xstep * WIDTH * 0.5;
	if (fract->fract_set == 0 || fract->fract_set == 1)
		fract->y_max = fract->y_center + fract->ystep * HEIGHT * 0.5;
	else if (fract->fract_set == 2)
		fract->y_max = fract->y_center - fract->ystep * HEIGHT * 0.5;
	return (0);
}

int	ft_move_key(int key, t_data *data)
{
	int	is_inversed;

	is_inversed = 1;
	if (data->fract.fract_set == 2)
		is_inversed = -1;
	if (key == 65361)
		data->fract.x_center -= data->fract.xstep * 20;
	else if (key == 65363)
		data->fract.x_center += data->fract.xstep * 20;
	else if (key == 65362)
		data->fract.y_center = data->fract.y_center + is_inversed * \
			data->fract.ystep * 20;
	else if (key == 65364)
		data->fract.y_center = data->fract.y_center - is_inversed * \
			data->fract.ystep * 20;
	ft_update_corner(&(data->fract));
	return (0);
}
// m for smooth mode c to swap colors
int	ft_key_input(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_destroy(data);
	else if (key == 99)
	{
		data->fract.color_number = (data->fract.color_number + 1) % 5;
		ft_printf("\ncolor number:%d", data->fract.color_number);
	}
	else if (key == 109)
	{
		data->fract.smoothed = (data->fract.smoothed + 1) % 2;
		if (data->fract.smoothed == 1)
			ft_printf("\nsmooth mode activated");
		else
			ft_printf("\nsmooth mode disabled");
	}
	else if (key >= 65361 && key <= 65364)
		ft_move_key(key, data);
	return (0);
}

void	ft_update_fract(t_fract *fract, double x, double y, double new_zoom)
{
	fract->x_center = x;
	fract->y_center = y;
	fract->zoom = new_zoom;
	fract->xstep = XSTEP * fract->zoom;
	fract->ystep = YSTEP * fract->zoom;
	fract->x_min = fract->x_center - fract->xstep * WIDTH * 0.5;
	if (fract->fract_set == 0 || fract->fract_set == 1)
		fract->y_max = fract->y_center + fract->ystep * HEIGHT * 0.5;
	else if (fract->fract_set == 2)
		fract->y_max = fract->y_center - fract->ystep * HEIGHT * 0.5;
}

int	ft_mouse_input(int button, int x, int y, t_fract *fract)
{
	double	x_coord;
	double	y_coord;

	x_coord = fract->x_min + x * fract->xstep;
	if (fract->fract_set == 0 || fract->fract_set == 1)
		y_coord = fract->y_max - y * fract->ystep;
	else if (fract->fract_set == 2)
		y_coord = fract->y_max + y * fract->ystep;
	if (button == 4)
		ft_update_fract(fract, x_coord, y_coord, fract->zoom * 0.8);
	if (button == 5)
		ft_update_fract(fract, x_coord, y_coord, fract->zoom * 1.25);
	if (button == 1 && fract->fract_set == 1)
	{
		fract->julia_cx = x_coord;
		fract->julia_cy = y_coord;
		fract->fract_set = 0;
		ft_printf("\nSwitched to Julia set\n");
	}
	return (0);
}

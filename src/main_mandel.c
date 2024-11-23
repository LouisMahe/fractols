/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:27:43 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 13:18:25 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_fract	ft_init_palettes(t_data data, t_fract fract)
{
	fract.palette = ft_cubic_first_palette(2048);
	if (fract.palette == NULL)
		ft_palette_error(data, NULL, NULL, NULL);
	fract.palette2 = ft_cubic_scd_palette(2048);
	if (fract.palette2 == NULL)
		ft_palette_error(data, fract.palette, NULL, NULL);
	fract.palette3 = ft_cubic_thrd_palette(2048);
	if (fract.palette3 == NULL)
		ft_palette_error(data, fract.palette, fract.palette2, NULL);
	fract.palette4 = ft_cubic_fourth_palette(2048);
	if (fract.palette4 == NULL)
		ft_palette_error(data, fract.palette, \
			fract.palette2, fract.palette3);
	return (fract);
}

t_fract	ft_init_mandel(t_data data, t_fract t_mandel, void *mlx)
{
	t_mandel = ft_init_palettes(data, t_mandel);
	t_mandel.mlx_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (t_mandel.mlx_img == NULL)
	{
		free(t_mandel.palette4);
		ft_palette_error(data, t_mandel.palette, \
			t_mandel.palette2, t_mandel.palette3);
	}
	t_mandel.addr = mlx_get_data_addr(t_mandel.mlx_img, \
		&t_mandel.bpp, &t_mandel.line_len, &t_mandel.endian);
	t_mandel.fract_set = 1;
	t_mandel.x_center = -0.7;
	t_mandel.y_center = 0;
	t_mandel.max_iter = 1000;
	t_mandel.color_number = 0;
	t_mandel.smoothed = 0;
	t_mandel.smooth_bound = 1 << 16;
	t_mandel.zoom = 1;
	t_mandel.x_min = t_mandel.x_center - XSTEP * t_mandel.zoom * WIDTH * 0.5;
	t_mandel.y_max = t_mandel.y_center + YSTEP * t_mandel.zoom * HEIGHT * 0.5;
	t_mandel.xstep = XSTEP * t_mandel.zoom;
	t_mandel.ystep = YSTEP * t_mandel.zoom;
	return (t_mandel);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.pmlx = mlx_init();
	if (!data.pmlx)
		exit (-1);
	data.pwin = mlx_new_window(data.pmlx, WIDTH, HEIGHT, "Fractol");
	if (!data.pwin)
	{
		mlx_destroy_display(data.pmlx);
		free(data.pmlx);
		exit (-1);
	}
	data = ft_parse(argc, argv, data);
	ft_draw_fract(&data);
	mlx_loop_hook(data.pmlx, &ft_draw_fract, &data);
	mlx_key_hook(data.pwin, &ft_key_input, &data);
	mlx_mouse_hook(data.pwin, &ft_mouse_input, &(data.fract));
	mlx_hook(data.pwin, 17, 0L, &ft_destroy, &data);
	mlx_loop(data.pmlx);
}

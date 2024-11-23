/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:25:42 by lmahe             #+#    #+#             */
/*   Updated: 2024/11/23 19:14:28 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

void	ft_display_options(t_data *data)
{
	ft_printf("Enter m for Mandelbrot, j for Julia and bs for Burning Ship\n");
	ft_printf("For Julia you can also provide two doubles for the constant\n");
	ft_printf("You can enable/disable the smooth mod using the key \'m\' and switch the color palette using \'c\'\n");
	ft_printf("You can move with the arrow keys, scroll to zoom/unzoom.\n");
	ft_printf("If you click on a point on the Mandelbrot set it will display the corresponding Julia set.\n");
	
	mlx_destroy_window(data->pmlx, data->pwin);
	data->pwin = NULL;
	mlx_destroy_display(data->pmlx);
	free(data->pmlx);
	exit (-1);
}

double	ft_atod(char *str, double res)
{
	double	sign;
	double	decimal;
	int		i;

	i = 0;
	sign = 1;
	decimal = 0.1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 8))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] <= '9' && str[i] >= '0')
		res = 10 * res + (double)(str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res + ((double)(str[i++] - '0')) * decimal;
		decimal = decimal * 0.1;
	}
	return (sign * res);
}

t_complex	ft_get_julia_start(int argc, char **argv)
{
	t_complex	c;

	c.x = 0;
	c.y = 0;
	c.iter = 0;
	if (argc != 4)
	{
		c.x = -0.8;
		c.y = 0.156;
	}
	else
	{
		c.x = ft_atod(argv[2], c.x);
		c.y = ft_atod(argv[3], c.y);
	}
	return (c);
}

t_data	ft_parse(int argc, char **argv, t_data data)
{
	t_complex	julia_c;

	if (argc < 2)
		ft_display_options(&data);
	if (ft_strcmp(argv[1], "m") == 0)
	{
		data.fract = ft_init_mandel(data, data.fract, data.pmlx);
		return (data);
	}
	else if (ft_strcmp(argv[1], "j") == 0)
	{
		julia_c = ft_get_julia_start(argc, argv);
		if (julia_c.iter == -1)
			ft_display_options(&data);
		data.fract = ft_init_julia(data, data.fract, julia_c.x, julia_c.y);
		return (data);
	}
	else if (ft_strcmp(argv[1], "bs") == 0)
	{
		data.fract = ft_init_ship(data, data.fract, data.pmlx);
		return (data);
	}
	else
		ft_display_options(&data);
	return (data);
}

int	ft_draw_fract(t_data *data)
{
	if (!data->fract.mlx_img)
		return (0);
	if (data->fract.fract_set == 1)
		ft_draw_mandel(data);
	else if (data->fract.fract_set == 0)
		ft_draw_julia(data);
	else if (data->fract.fract_set == 2)
		ft_draw_ship(data);
	return (0);
}

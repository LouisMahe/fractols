/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubic_interpol5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:49:39 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:26:13 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_cubic	ft_cubic_green_init4(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x2e;
	t_red.y[1] = 0x5d;
	t_red.y[2] = 0x8f;
	t_red.y[3] = 0xb2;
	t_red.y[4] = 0xb8;
	t_red.y[5] = 0xb8;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_blue_init4(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x28;
	t_red.y[1] = 0x52;
	t_red.y[2] = 0x61;
	t_red.y[3] = 0xab;
	t_red.y[4] = 0xa5;
	t_red.y[5] = 0xa5;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_red_init4(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x35;
	t_red.y[1] = 0x3d;
	t_red.y[2] = 0xc9;
	t_red.y[3] = 0xa5;
	t_red.y[4] = 0xd3;
	t_red.y[5] = 0xd3;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

int	*ft_cubic_fourth_palette(int size)
{
	t_cubic	t_red;
	t_cubic	t_green;
	t_cubic	t_blue;
	int		i;
	int		*palette;

	t_red.x[0] = 0;
	t_green.x[0] = 0;
	t_blue.x[0] = 0;
	t_red = ft_cubic_red_init4(t_red);
	t_green = ft_cubic_green_init4(t_green);
	t_blue = ft_cubic_blue_init4(t_blue);
	palette = malloc(size * sizeof(int));
	if (!palette)
		return (NULL);
	i = 0;
	while (i < size)
	{
		palette[i] = 0x00000000;
		palette[i] |= (int)ft_interpol_val((double)i / size, t_red) << 16;
		palette[i] |= (int)ft_interpol_val((double)i / size, t_green) << 8;
		palette[i] |= (int)ft_interpol_val((double)i / size, t_blue);
		i++;
	}
	return (palette);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubic_interpol3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:53:27 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:25:57 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_cubic	ft_cubic_green_init2(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x1b;
	t_red.y[1] = 0x3f;
	t_red.y[2] = 0x76;
	t_red.y[3] = 0xcd;
	t_red.y[4] = 0xf3;
	t_red.y[5] = 0xf3;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_blue_init2(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x2e;
	t_red.y[1] = 0x58;
	t_red.y[2] = 0x92;
	t_red.y[3] = 0xe4;
	t_red.y[4] = 0xf9;
	t_red.y[5] = 0xf9;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_red_init2(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x00;
	t_red.y[1] = 0x1d;
	t_red.y[2] = 0x53;
	t_red.y[3] = 0xb3;
	t_red.y[4] = 0xee;
	t_red.y[5] = 0xee;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

int	*ft_cubic_scd_palette(int size)
{
	t_cubic	t_red;
	t_cubic	t_green;
	t_cubic	t_blue;
	int		i;
	int		*palette;

	t_red.x[0] = 0;
	t_green.x[0] = 0;
	t_blue.x[0] = 0;
	t_red = ft_cubic_red_init2(t_red);
	t_green = ft_cubic_green_init2(t_green);
	t_blue = ft_cubic_blue_init2(t_blue);
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

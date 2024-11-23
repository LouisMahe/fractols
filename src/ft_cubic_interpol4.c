/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubic_interpol4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:49:39 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:25:42 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

t_cubic	ft_cubic_green_init3(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x39;
	t_red.y[1] = 0x55;
	t_red.y[2] = 0x67;
	t_red.y[3] = 0x7e;
	t_red.y[4] = 0xbc;
	t_red.y[5] = 0xbc;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_blue_init3(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x31;
	t_red.y[1] = 0x2b;
	t_red.y[2] = 0x56;
	t_red.y[3] = 0x68;
	t_red.y[4] = 0xad;
	t_red.y[5] = 0xad;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

t_cubic	ft_cubic_red_init3(t_cubic t_red)
{
	ft_init_xpoint(&t_red);
	t_red.y[0] = 0x38;
	t_red.y[1] = 0xa0;
	t_red.y[2] = 0x64;
	t_red.y[3] = 0x90;
	t_red.y[4] = 0xcc;
	t_red.y[5] = 0xcc;
	ft_get_delta(&t_red);
	ft_get_m(&t_red);
	ft_rescale(&t_red);
	return (t_red);
}

int	*ft_cubic_thrd_palette(int size)
{
	t_cubic	t_red;
	t_cubic	t_green;
	t_cubic	t_blue;
	int		i;
	int		*palette;

	t_red.x[0] = 0;
	t_green.x[0] = 0;
	t_blue.x[0] = 0;
	t_red = ft_cubic_red_init3(t_red);
	t_green = ft_cubic_green_init3(t_green);
	t_blue = ft_cubic_blue_init3(t_blue);
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

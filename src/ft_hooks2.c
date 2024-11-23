/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:22:05 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 11:34:11 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractols.h"

int	ft_destroy(t_data *data)
{
	mlx_destroy_image(data->pmlx, data->fract.mlx_img);
	mlx_destroy_window(data->pmlx, data->pwin);
	data->pwin = NULL;
	data->fract.mlx_img = NULL;
	mlx_loop_end(data->pmlx);
	mlx_destroy_display(data->pmlx);
	free(data->pmlx);
	free(data->fract.palette);
	free(data->fract.palette2);
	free(data->fract.palette3);
	free(data->fract.palette4);
	exit(1);
	return (0);
}

void	ft_palette_error(t_data data, int *p1, int *p2, int *p3)
{
	if (p3)
		free(p3);
	if (p2)
		free(p2);
	if (p1)
		free(p1);
	mlx_destroy_display(data.pmlx);
	free(data.pmlx);
	exit (-1);
}

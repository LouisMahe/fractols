/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:45:26 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/16 16:43:53 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printdigit(long int y, int *len)
{
	char	temp;

	temp = 0;
	if (y >= 10)
		ft_printdigit(y / 10, len);
	temp = (y % 10) + '0';
	write(1, &temp, 1);
	*len = *len + 1;
}

int	ft_printint(int x)
{
	long int	y;
	int			len;

	y = x;
	len = 0;
	if (y < 0)
	{
		y = -y;
		write(1, "-", 1);
		len++;
	}
	ft_printdigit(y, &len);
	return (len);
}

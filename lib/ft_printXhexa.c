/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printXhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:31:41 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/20 08:32:11 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdigituhexa(unsigned int x, int *len)
{
	char	temp;

	temp = 0;
	if (x >= HEXA)
		ft_printdigituhexa(x / HEXA, len);
	temp = HEXAU[x % HEXA];
	write(1, &temp, 1);
	*len = *len + 1;
}

int	ft_printuhexa(unsigned int x)
{
	int	len;

	len = 0;
	ft_printdigituhexa(x, &len);
	return (len);
}

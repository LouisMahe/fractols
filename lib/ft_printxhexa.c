/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:09:26 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/16 16:45:51 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdigitxhexa(unsigned int x, int *len)
{
	char	temp;

	temp = 0;
	if (x >= HEXA)
		ft_printdigitxhexa(x / HEXA, len);
	temp = HEXAL[x % HEXA];
	write(1, &temp, 1);
	*len = *len + 1;
}

int	ft_printlhexa(unsigned int x)
{
	int	len;

	len = 0;
	ft_printdigitxhexa(x, &len);
	return (len);
}

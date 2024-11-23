/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printudecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:51:45 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/16 16:48:26 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printdigit(unsigned int x, int *len)
{
	char	temp;

	temp = 0;
	if (x >= 10)
		ft_printdigit(x / 10, len);
	temp = (x % 10) + '0';
	write(1, &temp, 1);
	*len = *len + 1;
}

int	ft_printudecimal(unsigned int x)
{
	int	len;

	len = 0;
	ft_printdigit(x, &len);
	return (len);
}

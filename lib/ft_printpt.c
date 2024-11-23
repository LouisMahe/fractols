/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:43:58 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/05 14:24:26 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printpthexa(uintptr_t p, int *len)
{
	char	temp;

	temp = 0;
	if (p >= HEXA)
		ft_printpthexa(p / HEXA, len);
	temp = HEXAL[p % HEXA];
	write(1, &temp, 1);
	*len = *len + 1;
}

int	ft_printpt(uintptr_t p)
{
	int	len;

	len = 0;
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len += 2;
	ft_printpthexa(p, &len);
	return (len);
}

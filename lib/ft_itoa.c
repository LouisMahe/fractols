/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:38:46 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 10:53:04 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_digit_numb(long x)
{
	int	l;

	l = 1;
	while (x >= 10)
	{
		l++;
		x = x / 10;
	}
	return (l);
}

static void	ft_get_int(char *str, int sign, long int x, int size)
{
	int	i;

	i = size - 2;
	if (sign == 1)
		str[0] = '-';
	while (i >= sign)
	{
		str[i] = '0' + (x % 10);
		x = x / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	x;
	long int	sign;
	int			size;

	sign = 0;
	x = n;
	if (x < 0)
	{
		x = -x;
		sign = 1;
	}
	size = sign + ft_get_digit_numb(x) + 1;
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	str[size - 1] = 0;
	ft_get_int(str, sign, x, size);
	return (str);
}
